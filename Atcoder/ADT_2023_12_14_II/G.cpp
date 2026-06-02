#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll> v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		ll pivot = 1, p = i;
		for (ll j = 2; j * j <= i; ++j)
		{
			ll f = 0;
			while (p % j == 0)
			{
				p /= j;
				f ^= 1;
			}
			if (f)
			{
				pivot *= j;
			}
		}
		v[pivot * p]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += v[i] * v[i];
	}
	cout << ans;
	return 0;
}
