#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[200002][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(2));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> v[i][j];
		}
	}
	function<ll(int, int)> dfs = [&](int idx, int flag)
		{
			if (idx == n + 1)
			{
				return 1LL;
			}
			if (dp[idx][flag] != -1)
			{
				return dp[idx][flag];
			}
			ll res = 0, pre = v[idx - 1][flag];
			for (int i = 0; i < 2; ++i)
			{
				if (pre != v[idx][i])
				{
					res = (res + dfs(idx + 1, i)) % MOD;
				}
			}
			return dp[idx][flag] = res;
		};
	cout << (dfs(2, 0) + dfs(2, 1)) % MOD;
	return 0;
}
