#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
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
	vector<ll>dp((1 << 11));
	dp[1] = 1;
	ll ans = 1;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		ans = (ans * power(a)) % MOD;
		vector<ll>temp((1 << 11));
		for (int j = 0; j < (1 << 11); ++j)
		{
			if (!dp[j])
			{
				continue;
			}
			for (int k = 1; k <= min(10, a); ++k)
			{
				int p = j;
				for (int z = 0; z + k <= 10; ++z)
				{
					if (j & (1 << z))
					{
						p |= (1 << (k + z));
					}
				}
				temp[p] = (temp[p] + dp[j]) % MOD;
			}
			temp[j] = (temp[j] + dp[j] * (a - min(10, a))) % MOD;
		}
		dp = move(temp);
	}
	ll res = 0;
	for (int i = 0; i < (1 << 11); ++i)
	{
		if (i & (1 << 10))
		{
			res = (res + dp[i]) % MOD;
		}
	}
	cout << (ans * res) % MOD;
	return 0;
}
