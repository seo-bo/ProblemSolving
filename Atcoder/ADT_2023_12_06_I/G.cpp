#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = -1;
	for (int i = 0; i < m; ++i)
	{
		ll a = 0;
		cin >> a;
		auto it = upper_bound(v.begin(), v.end(), a + k);
		if (it == v.begin())
		{
			continue;
		}
		ll p = *prev(it);
		if (llabs(a - p) <= k)
		{
			ans = max(ans, p + a);
		}
	}
	cout << ans;
	return 0;
}
