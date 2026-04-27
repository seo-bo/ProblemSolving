#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, d = 0;
	cin >> n >> d;
	ll ans = 0, lim = 2000000;
	vector<ll>v(lim + 1, 1);
	for (int i = 2; i <= lim; ++i)
	{
		v[i] = (v[i - 1] * 2) % MOD;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i + d <= n)
		{
			ans = (ans + v[i + d] * 2 % MOD) % MOD;
		}
		ll left = max(1LL, i + d - n), right = d / 2;
		if (left <= right)
		{
			ll len = ((right - left + 1) * 2 % MOD - (d % 2 == 0) + MOD) % MOD * v[d] % MOD;
			ans = (ans + v[i] * len % MOD) % MOD;
		}
	}
	cout << ans;
	return 0;
}
