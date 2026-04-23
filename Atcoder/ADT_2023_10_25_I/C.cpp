#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n + 1, vector<char>(m + 1));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>>visited(n + 1, vector<int>(m + 1, INT_MAX));
	queue<pii>q;
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'o')
			{
				if (sx)
				{
					ex = i, ey = j;
				}
				else
				{
					sx = i, sy = j;
				}
			}
		}
	}
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && visited[nx][ny] > visited[x][y] + 1)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << visited[ex][ey];
	return 0;
}
