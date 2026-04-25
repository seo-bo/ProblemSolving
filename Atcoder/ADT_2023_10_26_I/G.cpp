#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	vector<ll>v(n + 1), prefix(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin() + 1, v.end());
	for (ll i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + v[i];
	}
	ll ans = 0;
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0;
		cin >> a;
		if (a >= p)
		{
			ans += n * p;
			continue;
		}
		ll idx = upper_bound(v.begin() + 1, v.end(), p - a) - v.begin() - 1;
		ans += prefix[idx] + idx * a + p * (n - idx);
	}
	cout << ans;
	return 0;
}
