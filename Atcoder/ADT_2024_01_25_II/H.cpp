#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>dp(n + 1);
	dp[n] = 1;
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
	for (int i = 1; i <= k; ++i)
	{
		vector<ll>temp(n + 1);
		temp[n] = 1;
		for (int j = 0; j < n; ++j)
		{
			ll sum = 0;
			for (int a = 1; a <= m; ++a)
			{
				ll nxt = j + a;
				if (nxt >= n)
				{
					nxt = 2 * n - nxt;
				}
				temp[j] = (temp[j] + dp[nxt]) % MOD;
			}
			temp[j] = temp[j] * power(m) % MOD;
		}
		dp = move(temp);
	}
	cout << dp[0];
	return 0;
}
