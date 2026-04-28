#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	vector<int>per = { 0 };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	map<int, int>mm;
	int ans = 0;
	vector<vector<int>>dir = { {0,1},{1,0} };
	function<void(int, int)> dfs = [&](int x, int y)
		{
			if (x == n && y == m)
			{
				ans++;
				return;
			}
			int pivot = v[x][y];
			mm[pivot]++;
			for (int i = 0; i < 2; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
				{
					int nxt = v[nx][ny];
					if (mm.find(nxt) == mm.end())
					{
						dfs(nx, ny);
					}
				}
			}
			if (--mm[pivot] == 0)
			{
				mm.erase(pivot);
			}
		};
	dfs(1, 1);
	cout << ans;
	return 0;
}
