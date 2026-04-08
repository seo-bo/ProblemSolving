#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<vector<int>>>dir = { {{0,1},{1,0}},{{0,-1},{1,0}},{{-1,0},{0,1}},{{-1,0},{0,-1}},
		{{1,0},{-1,0}},{{0,-1},{0,1}} };
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>v(n + 2, vector<int>(n + 2));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	auto cal = [&]
		{
			if (v[1][1] != 1 && v[1][1] != 5)
			{
				return INT_MAX;
			}
			vector<vector<int>>visited(n + 2, vector<int>(n + 2, INT_MAX));
			queue<pii>q;
			visited[1][1] = 1;
			q.push(make_pair(1, 1));
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();
				for (auto& i : dir[v[x][y]])
				{
					int nx = x + i[0], ny = y + i[1];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n + 1 && visited[nx][ny] > visited[x][y] + 1)
					{
						if (ny == n + 1)
						{
							visited[nx][ny] = visited[x][y] + 1;
							continue;
						}
						int flag = 0;
						for (auto& j : dir[v[nx][ny]])
						{
							int px = nx + j[0], py = ny + j[1];
							if (px == x && py == y)
							{
								flag = 1;
								break;
							}
						}
						if (flag)
						{
							visited[nx][ny] = visited[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			return visited[n][n + 1];
		};
	int ans = INT_MAX;
	if (!k)
	{
		ans = cal();
	}
	for (int x = 1; x <= n && k; ++x)
	{
		for (int y = 1; y <= n; ++y)
		{
			int save = v[x][y];
			for (int j = 0; j <= 5; ++j)
			{
				if (save == j)
				{
					continue;
				}
				v[x][y] = j;
				ans = min(ans, cal());
			}
			v[x][y] = save;
		}
	}
	cout << ((ans == INT_MAX) ? -1 : ans - 1);
	return 0;
}