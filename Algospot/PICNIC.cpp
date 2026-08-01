#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1 << 11];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		memset(dp, -1, sizeof(dp));
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		function<ll(int)> dfs = [&](int mask)
			{
				if (mask == (1 << n) - 1)
				{
					return 1LL;
				}
				if (dp[mask] != -1)
				{
					return dp[mask];
				}
				ll res = 0;
				for (int i = 0; i < n; ++i)
				{
					if (mask & (1 << i))
					{
						continue;
					}
					for (auto& j : graph[i])
					{
						if (mask & (1 << j))
						{
							continue;
						}
						res += dfs(mask | (1 << i) | (1 << j));
					}
					break;
				}
				return dp[mask] = res;
			};
		cout << dfs(0) << '\n';
	}
	return 0;
}
