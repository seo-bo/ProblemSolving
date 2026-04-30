#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>dp(n + 1);
	dp[0] = 1;
	auto power = [&](ll base)
		{
			ll exp = MOD - 2, res = 1;
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
	ll pivot = power(m);
	for (int i = 1; i <= k; ++i)
	{
		vector<ll>temp(n + 1);
		temp[n] = dp[n];
		for (int j = 1; j <= m; ++j)
		{
			for (int z = 0; z <= n - 1; ++z)
			{
				if (!dp[z])
				{
					continue;
				}
				int pos = z + j;
				if (z + j > n)
				{
					pos = 2 * n - z - j;
				}
				temp[pos] = (temp[pos] + dp[z] * pivot) % MOD;
			}
		}
		dp = move(temp);
	}
	cout << dp[n];
	return 0;
}
