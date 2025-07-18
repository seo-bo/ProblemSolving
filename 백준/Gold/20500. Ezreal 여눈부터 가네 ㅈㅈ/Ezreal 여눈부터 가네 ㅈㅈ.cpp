#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto power = [&](ll base)
		{
			ll res = 1, exp = MOD - 2;
			while (exp)
			{
				if (exp & 1)
				{
					res = (base * res) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	vector<ll>fact(1601, 1);
	for (ll i = 2; i <= 1600; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	ll n = 0;
	cin >> n;
	n--;
	ll ans = 0;
	for (ll i = 0; i <= n; ++i)
	{
		ll temp = 5 + (i * 5) + (n - i);
		if (temp % 3 == 0)
		{
			ans = (ans + fact[n] * power(fact[i]) % MOD * power(fact[n - i]) % MOD) % MOD;
		}
	}
	cout << ans;
	return 0;
}