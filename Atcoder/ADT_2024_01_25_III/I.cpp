#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, k = 0;
	cin >> h >> w >> k;
	int lim = 1e6;
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
	vector<ll>fact(lim + 5, 1), inv(lim + 5, 1);
	for (int i = 2; i <= lim + 3; ++i)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = power(fact[i]);
	}
	ll ans = 0, base = fact[h * w] * inv[k] % MOD * inv[h * w - k] % MOD;
	auto cal = [&](int n, int m)
		{
			ll res = 0;
			for (int i = 0; i < (1 << 4); ++i)
			{
				int row = n, col = m;
				if (i & 1)
				{
					row--;
				}
				if (i & 2)
				{
					col--;
				}
				if (i & 4)
				{
					row--;
				}
				if (i & 8)
				{
					col--;
				}
				if (row < 0 || col < 0)
				{
					continue;
				}
				ll len = row * col;
				if (len < k)
				{
					continue;
				}
				ll temp = fact[len] * inv[k] % MOD * inv[len - k] % MOD;
				if (__builtin_popcount(i) % 2)
				{
					res = (res - temp + MOD) % MOD;
					continue;
				}
				res = (res + temp) % MOD;
			}
			return res;
		};
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (k > i * j)
			{
				continue;
			}
			ll cnt = (w - j + 1) * (h - i + 1), t = cal(i, j);
			ans = (ans + t * cnt % MOD * i * j % MOD) % MOD;
		}
	}
	cout << ans * power(base) % MOD;
	return 0;
}
