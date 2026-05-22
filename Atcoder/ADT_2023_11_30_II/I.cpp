#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0, inv = (MOD + 1) / 2;
	cin >> n >> q;
	vector<ll> v(n + 1);
	vector<vector<ll>> BIT(4, vector<ll>(n + 1));
	auto update = [&](ll idx, ll delta)
	{
		ll pivot = 1;
		for (int i = 1; i <= 3; ++i)
		{
			ll x = idx, diff = (delta - v[x] + MOD) % MOD * pivot % MOD;
			while (x <= n)
			{
				BIT[i][x] = (BIT[i][x] + diff) % MOD;
				x += x & -x;
			}
			pivot = (pivot * idx) % MOD;
		}
	};
	auto query = [&](ll idx)
	{
		ll ans = 0;
		vector<ll> base = {0, (idx * idx + 3 * idx + 2) % MOD * inv % MOD, (MOD - (2 * idx + 3) % MOD) * inv % MOD, inv};
		for (int i = 1; i <= 3; ++i)
		{
			base[i] = (base[i] + MOD) % MOD;
			ll res = 0, x = idx;
			while (x)
			{
				res = (res + BIT[i][x]) % MOD;
				x -= x & -x;
			}
			ans = (ans + res * base[i] % MOD) % MOD;
		}
		return ans;
	};
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		update(i, a);
		v[i] = a;
	}
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 2)
		{
			cout << query(b) << '\n';
			continue;
		}
		cin >> c;
		update(b, c);
		v[b] = c;
	}
	return 0;
}
