#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>fact(n + 1, 1), inv(n + 1, 1);
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
	for (int i = 2; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i]);
	}
	vector<int>degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
	}
	int odd = 0, even = 0, tot = 0;
	for (int i = 1; i <= n; ++i)
	{
		int p = degree[i] % 2;
		odd += (p == 1), even += (p == 0);
		tot = (tot + p) % 2;
	}
	ll ans = 0;
	for (int i = tot; i <= min(k, odd); i += 2)
	{
		if (k - i > even)
		{
			continue;
		}
		ll a = fact[odd] * inv[i] % MOD * inv[odd - i] % MOD;
		ll b = fact[even] * inv[k - i] % MOD * inv[even - k + i] % MOD;
		ans = (ans + a * b % MOD) % MOD;
	}
	cout << ans;
	return 0;
}
