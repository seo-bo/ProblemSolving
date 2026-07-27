#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int> tp;

int visited[501][501][6];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	string base = "snuke";
	vector<vector<char>> v(h + 1, vector<char>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
		}
	}
	if (v[1][1] != 's')
	{
		cout << "No";
		return 0;
	}
	queue<tp> q;
	q.push(make_tuple(1, 1, 0));
	visited[1][1][0] = 1;
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!q.empty())
	{
		auto [x, y, now] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nxt = (now + 1) % 5;
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && v[nx][ny] == base[nxt])
			{
				if (!visited[nx][ny][nxt])
				{
					visited[nx][ny][nxt] = 1;
					q.push(make_tuple(nx, ny, nxt));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 5; ++i)
	{
		ans |= visited[h][w][i];
	}
	cout << ((ans) ? "Yes" : "No");
	return 0;
}
