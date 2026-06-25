#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	auto power = [&](ll base, ll exp, ll mod)
		{
			ll res = 1;
			base %= mod;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % mod;
				}
				base = (base * base) % mod;
				exp >>= 1;
			}
			return res;
		};
	if (m % MOD == 0)
	{
		cout << 0;
		return 0;
	}
	cout << power(m, power(k, n, MOD - 1), MOD);
	return 0;
}
