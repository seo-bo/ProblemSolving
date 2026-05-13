#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, w = 0;
	cin >> n >> w;
	vector<pll> v(n);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	for (int i = 0; i < n && w; ++i)
	{
		auto [a, b] = v[i];
		ll pivot = min(w, b);
		ans += pivot * a;
		w -= pivot;
	}
	cout << ans;
	return 0;
}
