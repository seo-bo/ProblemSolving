#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[101][101][101];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ll ans = 0;
	auto cal = [&](int lim)
	{
		memset(dp, -1, sizeof(dp));
		function<ll(int, int, int)> dfs = [&](int idx, int sum, int pick)
		{
			if (idx > n)
			{
				return (ll)(pick == lim && sum == 0);
			}
			if (dp[idx][sum][pick] != -1)
			{
				return dp[idx][sum][pick];
			}
			ll res = dfs(idx + 1, sum, pick);
			if (pick < lim)
			{
				res = (res + dfs(idx + 1, (sum + v[idx]) % lim, pick + 1)) % MOD;
			}
			return dp[idx][sum][pick] = res;
		};
		ans = (ans + dfs(1, 0, 0)) % MOD;
	};
	for (int i = 1; i <= n; ++i)
	{
		cal(i);
	}
	cout << ans;
	return 0;
}
