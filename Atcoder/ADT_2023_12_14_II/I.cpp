#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

ll op(ll a, ll b)
{
	return a + b;
}

ll e()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll> v(n);
	vector<ll> A(1, -1);
	for (auto &[i, _] : v)
	{
		cin >> i;
		A.push_back(i);
	}
	for (auto &[_, i] : v)
	{
		cin >> i;
		A.push_back(i);
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	for (auto &[a, b] : v)
	{
		a = lower_bound(A.begin(), A.end(), a) - A.begin();
		b = lower_bound(A.begin(), A.end(), b) - A.begin();
	}
	sort(v.begin(), v.end(), [&](const pll &a, const pll &b)
		 {
		if(a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first < b.first; });
	int len = A.size() + 5;
	segtree<ll, op, e> seg(len);
	ll ans = 0, pa = 0, pb = 0, cnt = 0;
	for (auto &[a, b] : v)
	{
		if (a == pa && b == pb)
		{
			cnt++;
			continue;
		}
		seg.set(pb, seg.get(pb) + cnt);
		ans += cnt * seg.prod(pb, len);
		pa = a, pb = b, cnt = 1;
	}
	seg.set(pb, seg.get(pb) + cnt);
	ans += cnt * seg.prod(pb, len);
	cout << ans;
	return 0;
}
