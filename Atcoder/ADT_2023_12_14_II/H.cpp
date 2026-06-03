#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	// [1 [2 [3 [4 [5 6 5] 4] 3] 2] 1]
	// 0 1 3 6 10 15 20
	// 1 2 3 4 5 6 7 8 9 10 11
	ll n = 0;
	cin >> n;
	vector<vector<ll>> v(n + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		v[a].push_back(i);
		ll lim = n - i + 1;
		if (i <= lim)
		{
			ans += i * (i - 1) / 2;
		}
		else
		{
			ans += lim * (lim + 1) / 2 + (i - 1 - lim) * lim;
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		ll len = v[i].size();
		if (len <= 1)
		{
			continue;
		}
		vector<ll> prefix(len + 1);
		for (ll j = 1; j <= len; ++j)
		{
			prefix[j] = prefix[j - 1] + v[i][j - 1];
		}
		while (v[i].size() > 1)
		{
			ll cur = v[i].back(), lim = n - cur + 1;
			v[i].pop_back(), len--;
			ll idx = upper_bound(v[i].begin(), v[i].end(), lim) - v[i].begin();
			ans -= prefix[idx] + (len - idx) * lim;
		}
	}
	cout << ans;
	return 0;
}
