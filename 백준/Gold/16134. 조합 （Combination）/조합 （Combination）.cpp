#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	ll a = n - k;
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
	ll res = 1, temp = 1;
	for (ll i = 2; i <= n; ++i)
	{
		temp = (temp * i) % MOD;
		if (i == n)
		{
			res = (res * temp) % MOD;
		}
		if (i == k)
		{
			res = (res * power(temp)) % MOD;
		}
		if (i == a)
		{
			res = (res * power(temp)) % MOD;
		}
	}
	cout << res;
	return 0;
}