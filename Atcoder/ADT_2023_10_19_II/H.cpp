#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, vector<int>>v;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a].push_back(i);
	}
	vector<ll>BIT(n + 3);
	auto update = [&](int idx, ll delta)
		{
			while (idx <= n)
			{
				BIT[idx] = (BIT[idx] + delta + MOD) % MOD;
				idx += idx & -idx;
			}
		};
	auto query = [&](int idx)
		{
			ll res = 0;
			while (idx)
			{
				res = (res + BIT[idx] + MOD) % MOD;
				idx -= idx & -idx;
			}
			return res;
		};
	vector<ll>two(n + 3, 1);
	for (int i = 1; i <= n; ++i)
	{
		two[i] = two[i - 1] * 2 % MOD;
		update(i, two[i]);
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
	ll ans = 0;
	for (auto& [a, b] : v)
	{
		for (auto& j : b)
		{
			ans = (ans + (power(two[j + 1]) * (query(n) - query(j) + MOD) % MOD) % MOD) % MOD;
		}
		for (auto& j : b)
		{
			update(j, -two[j]);
		}
	}
	cout << ans;
	return 0;
}
