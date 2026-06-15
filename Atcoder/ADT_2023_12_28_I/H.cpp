#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll op(ll a, ll b)
{
	return (a + b) % MOD;
}

ll e()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> v[i];
	}
	segtree<ll, op, e>dp(n + 3);
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
	for (int i = n - 1; i >= 1; --i)
	{
		ll a = (dp.prod(i + 1, i + v[i] + 1) + v[i] + 1) % MOD * power(v[i]) % MOD;
		dp.set(i, a);
	}
	cout << dp.get(1);
	return 0;
}
