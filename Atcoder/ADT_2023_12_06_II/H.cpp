#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	vector<vector<int>> punch = {{0, -1}, {0, 0}, {0, 1}, {0, -2}, {0, 2}};
	vector<vector<char>> v(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
	dist[1][1] = 0;
	deque<pii> dq;
	dq.push_back(make_pair(1, 1));
	while (!dq.empty())
	{
		auto [x, y] = dq.front();
		dq.pop_front();
		if (x == n && y == m)
		{
			cout << dist[x][y];
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (v[nx][ny] == '#')
				{
					continue;
				}
				if (dist[nx][ny] > dist[x][y])
				{
					dist[nx][ny] = dist[x][y];
					dq.push_front(make_pair(nx, ny));
				}
			}
		}
		for (int i = -2; i <= 2; ++i)
		{
			int pp = (abs(i) == 2) ? 3 : 5;
			for (int j = 0; j < pp; ++j)
			{
				int nx = x + i;
				int ny = y + punch[j][1];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
				{
					if (dist[nx][ny] > dist[x][y] + 1)
					{
						dist[nx][ny] = dist[x][y] + 1;
						dq.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return 0;
}
