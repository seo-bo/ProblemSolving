#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(n);
	ll tot = 0;
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		tot += b;
	}
	v.push_back(make_pair(0, 0));
	sort(v.rbegin(), v.rend());
	ll base = v[0].first + 1;
	while (!v.empty())
	{
		auto [a, b] = v.back();
		ll p = a;
		while (!v.empty() && v.back().first <= p)
		{
			tot -= v.back().second;
			v.pop_back();
		}
		if (tot <= k)
		{
			cout << p + 1;
			return 0;
		}
	}
	cout << base;
	return 0;
}
