#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[401][401];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>v(2 * n + 1, vector<ll>(2 * n + 1));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;
	}
	auto power = [&](ll base)
		{
			ll res = 1, exp = MOD - 2;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	vector<ll>fact(n + 1, 1), inv(n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i]);
	}
	function<ll(int, int)> dfs = [&](int left, int right)
		{
			if (left > right)
			{
				return 1LL;
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			ll res = 0, len = (right - left + 1) / 2;
			for (int i = left + 1; i <= right; i += 2)
			{
				if (!v[left][i])
				{
					continue;
				}
				int rlen = (right - i) / 2;
				ll pivot = dfs(left + 1, i - 1) % MOD * dfs(i + 1, right) % MOD;
				pivot = pivot * fact[len] % MOD * inv[len - rlen] % MOD * inv[rlen] % MOD;
				res = (res + pivot) % MOD;
			}
			return dp[left][right] = res;
		};
	cout << dfs(1, 2 * n);
	return 0;
}
