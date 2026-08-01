#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>v(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				char a;
				cin >> a;
				v[i][j] = (a == '#');
			}
		}
		vector<vector<vector<int>>>dir = { {{1,0},{1,1}},{{1,-1},{1,0}},{{1,0},{0,1}},{{0,1},{1,1}} };
		int ans = 0;
		function<void(int, int)> dfs = [&](int x, int y)
			{
				if (x == n + 1)
				{
					ans++;
					return;
				}
				if (v[x][y])
				{
					int nx = x, ny = y + 1;
					if (ny == m + 1)
					{
						nx++, ny = 1;
					}
					dfs(nx, ny);
					return;
				}
				for (int i = 0; i < 4; ++i)
				{
					int flag = 1;
					for (int j = 0; j < 2 && flag; ++j)
					{
						int nx = x + dir[i][j][0];
						int ny = y + dir[i][j][1];
						if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !v[nx][ny]))
						{
							flag = 0;
						}
					}
					if (flag)
					{
						int nx = x, ny = y + 1;
						if (ny == m + 1)
						{
							nx++, ny = 1;
						}
						v[x][y] = 1;
						for (int j = 0; j < 2; ++j)
						{
							int xx = x + dir[i][j][0];
							int yy = y + dir[i][j][1];
							v[xx][yy] = 1;
						}
						dfs(nx, ny);
						v[x][y] = 0;
						for (int j = 0; j < 2; ++j)
						{
							int xx = x + dir[i][j][0];
							int yy = y + dir[i][j][1];
							v[xx][yy] = 0;
						}
					}
				}
			};
		dfs(1, 1);
		cout << ans << '\n';
	}
	return 0;
}
