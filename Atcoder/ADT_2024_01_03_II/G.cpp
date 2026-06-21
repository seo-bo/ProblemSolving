#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<char>>v(h + 1, vector<char>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>>visited(h + 1, vector<int>(w + 1, INT_MAX));
	visited[1][1] = 1;
	queue<pii>q;
	q.push(make_pair(1, 1));
	vector<vector<int>>dir = { {0,1},{1,0} };
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && v[nx][ny] == '.')
			{
				if (visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int ans = 1;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (visited[i][j] == INT_MAX)
			{
				continue;
			}
			ans = max(ans, visited[i][j]);
		}
	}
	cout << ans;
	return 0;
}
