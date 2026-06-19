#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll h = 0, w = 0, n = 0;
	cin >> h >> w >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	ll a = 0, b = 0;
	cin >> a;
	vector<ll>A(a);
	for (auto& i : A)
	{
		cin >> i;
	}
	cin >> b;
	vector<ll>B(b);
	for (auto& i : B)
	{
		cin >> i;
	}
	A.push_back(h), B.push_back(w);
	map<pll, ll>mm;
	for (auto& [a, b] : v)
	{
		auto it = lower_bound(A.begin(), A.end(), a);
		auto jt = lower_bound(B.begin(), B.end(), b);
		mm[make_pair(*it, *jt)]++;
	}
	ll ans1 = LLONG_MAX, ans2 = LLONG_MIN;
	for (auto& [_, i] : mm)
	{
		ans1 = min(ans1, i);
		ans2 = max(ans2, i);
	}
	if (mm.size() != (a + 1) * (b + 1))
	{
		ans1 = 0;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
