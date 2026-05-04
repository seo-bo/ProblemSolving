#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>v(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n - 1; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<ll>dp(1 << (n + 1), -1);
	function<ll(int)> dfs = [&](int mask)
		{
			if (__builtin_popcount(mask) == n)
			{
				return 0LL;
			}
			if (dp[mask] != -1)
			{
				return dp[mask];
			}
			ll res = 0;
			for (int i = 1; i <= n - 1; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					if (mask & (1 << i) || mask & (1 << j))
					{
						continue;
					}
					res = max(res, dfs(mask | (1 << i) | (1 << j)) + v[i][j]);
				}
			}
			return dp[mask] = res;
		};
	cout << dfs(0);
	return 0;
}
