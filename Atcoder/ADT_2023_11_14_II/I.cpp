#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void) // 포배원?
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0;
	cin >> n >> l;
	vector<ll> v(n);
	for (auto &i : v)
	{
		string str;
		cin >> str;
		for (auto &j : str)
		{
			i |= (1LL << (j - 'a'));
		}
	}
	auto power = [&](ll base, ll exp)
	{
		ll res = 1;
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
	ll ans = 0;
	for (ll i = 1; i < (1 << n); ++i)
	{
		ll temp = (1LL << 26) - 1;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				temp &= v[j];
			}
		}
		ll a = __builtin_popcount(i), b = __builtin_popcount(temp);
		ll res = power(b, l);
		if (a % 2)
		{
			ans = (ans + res) % MOD;
		}
		else
		{
			ans = (ans - res + MOD) % MOD;
		}
	}
	cout << ans;
	return 0;
}
