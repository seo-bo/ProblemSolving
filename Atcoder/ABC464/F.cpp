#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
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
	vector<ll>v(n + 1), fact(n + 1, 1), inv(n + 1, 1);
	ll tot = 0;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i]);
		tot = (tot + v[i]) % MOD;
	}
	auto sv = [&](ll siz, ll start)
		{
			vector<vector<ll>>temp(siz + 1);
			for (ll i = 0; i < (1 << siz); ++i)
			{
				ll sum = 0, cnt = 0;
				for (ll j = 0; j < siz; ++j)
				{
					if (i & (1 << j))
					{
						ll nxt = start + j;
						sum += v[nxt];
						cnt++;
					}
				}
				if (sum == -1)
				{
					continue;
				}
				temp[cnt].push_back(sum);
			}
			for (auto& i : temp)
			{
				sort(i.begin(), i.end());
			}
			return temp;
		};
	ll lsiz = (n + 1) / 2, rsiz = n - lsiz;
	vector<vector<ll>>left = sv(lsiz, 1), right = sv(rsiz, lsiz + 1);
	vector<vector<ll>>prefix(rsiz + 1, vector<ll>(1));
	for (ll i = 0; i <= rsiz; ++i)
	{
		ll len = right[i].size();
		for (ll j = 1; j <= len; ++j)
		{
			prefix[i].push_back((prefix[i].back() + right[i][j - 1]) % MOD);
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= lsiz; ++i)
	{
		for (auto& j : left[i])
		{
			for (ll k = 0; k <= rsiz; ++k)
			{
				ll need = x - j, p = i + k;
				auto it = lower_bound(right[k].begin(), right[k].end(), need) - right[k].begin();
				if (!it || p == n)
				{
					continue;
				}
				ll t = (it * ((tot - j % MOD + MOD) % MOD) % MOD - prefix[k][it] + MOD) % MOD;
				t = t * fact[p] % MOD * fact[n - p - 1] % MOD;
				ans = (ans + t) % MOD;
			}
		}
	}
	cout << ans * inv[n] % MOD;
	return 0;
}
