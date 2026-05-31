#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int lim = 1e6;
	vector<bool> prime(lim + 3, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i * i <= lim; ++i)
	{
		if (prime[i])
		{
			for (ll j = i * i; j <= lim; j += i)
			{
				prime[j] = false;
			}
		}
	}
	vector<ll> v;
	for (ll i = 2; i <= lim; ++i)
	{
		if (prime[i])
		{
			v.push_back(i);
		}
	}
	ll ans = 0, n = 0, len = v.size();
	cin >> n;
	for (ll i = 0; i < len && v[i] * v[i] * v[i] <= n; ++i)
	{
		ll p = n / (v[i] * v[i] * v[i]);
		ll mini = min(v[i] - 1, p);
		ans += upper_bound(v.begin(), v.end(), mini) - v.begin();
	}
	cout << ans;
	return 0;
}
