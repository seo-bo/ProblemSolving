#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, ll>mm;
	ll n = 0, k = 0;
	cin >> n >> k;
	for (ll i = 2; i <= n; ++i)
	{
		mm[i * (i - 1) / 2] = i;
	}
	if (k == 1)
	{
		cout << "Infinity";
		return 0;
	}
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	map<tp, ll>cnt;
	sort(v.begin(), v.end());
	for (ll i = 0; i < n; ++i)
	{
		auto [sx, sy] = v[i];
		for (ll j = i + 1; j < n; ++j)
		{
			auto [ex, ey] = v[j];
			ll a = ex - sx, b = ey - sy;
			ll g = gcd(llabs(a), llabs(b));
			a /= g, b /= g;
			ll c = a * sy - b * sx;
			cnt[make_tuple(a, b, c)]++;
		}
	}
	ll ans = 0;
	for (auto& [a, b] : cnt)
	{
		if (mm[b] >= k)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
