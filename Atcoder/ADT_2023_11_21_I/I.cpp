#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

ll op(ll a, ll b)
{
	return min(a, b);
}

ll e()
{
	return LLONG_MAX;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll ans = 0;
	vector<ll> save(1);
	vector<ll> v(n);
	vector<pll> coupon(m);
	for (auto &i : v)
	{
		cin >> i;
		save.push_back(i);
		ans += i;
	}
	for (auto &[a, _] : coupon)
	{
		cin >> a;
		save.push_back(a);
	}
	for (auto &[_, b] : coupon)
	{
		cin >> b;
	}
	sort(coupon.begin(), coupon.end(), [&](const pll &a, const pll &b)
		 {
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second; });
	sort(save.begin(), save.end());
	save.erase(unique(save.begin(), save.end()), save.end());
	int len = save.size();
	segtree<ll, op, e> seg(len + 2);
	map<ll, ll> cnt;
	for (auto &i : v)
	{
		int idx = lower_bound(save.begin(), save.end(), i) - save.begin();
		seg.set(idx, idx);
		cnt[idx]++;
	}
	for (auto &[i, dis] : coupon)
	{
		int left = lower_bound(save.begin(), save.end(), i) - save.begin();
		ll a = seg.prod(left, len + 1);
		if (a == LLONG_MAX)
		{
			continue;
		}
		ans -= dis;
		if (--cnt[a] == 0)
		{
			seg.set(a, LLONG_MAX);
		}
	}
	cout << ans;
	return 0;
}
