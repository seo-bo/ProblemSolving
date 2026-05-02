#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
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
	ll n = 0, p = 0;
	cin >> n >> p;
	ll inva = p * power(100) % MOD, invb = (100 - p) * power(100) % MOD;
	vector<ll>dp(n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (inva * dp[i - 2] % MOD + invb * dp[i - 1] % MOD + 1) % MOD;
	}
	cout << dp[n];
	return 0;
}
