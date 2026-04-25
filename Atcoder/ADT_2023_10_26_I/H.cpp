#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	vector<vector<char>>v(n + 1, vector<char>(n + 1));
	vector<vector<int>>dir = { {}, {-1,-1},{-1,1},{1,-1},{1,1} };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>>visited(n + 1, vector<vector<int>>(n + 1, vector<int>(5, INT_MAX)));
	visited[sx][sy][0] = 0;
	queue<tp>q;
	q.push(make_tuple(sx, sy, 0));
	while (!q.empty())
	{
		auto [x, y, d] = q.front();
		q.pop();
		for (int i = 1; i <= 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int co = (d != i);
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && v[nx][ny] == '.')
			{
				if (visited[nx][ny][i] > visited[x][y][d] + co)
				{
					visited[nx][ny][i] = visited[x][y][d] + co;
					q.push(make_tuple(nx, ny, i));
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= 4; ++i)
	{
		ans = min(ans, visited[ex][ey][i]);
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
