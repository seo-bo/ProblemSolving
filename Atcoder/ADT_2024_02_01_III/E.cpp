#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	unordered_map<int, int> mm;
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	int base = n + m - 1, ans = 0;
	mm[v[1][1]]++;
	vector<vector<int>> dir = {{0, 1}, {1, 0}};
	function<void(int, int)> dfs = [&](int x, int y)
	{
		if (x == n && y == m)
		{
			ans += (mm.size() == base);
			return;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				mm[v[nx][ny]]++;
				dfs(nx, ny);
				if (--mm[v[nx][ny]] == 0)
				{
					mm.erase(v[nx][ny]);
				}
			}
		}
	};
	dfs(1, 1);
	cout << ans;
	return 0;
}
