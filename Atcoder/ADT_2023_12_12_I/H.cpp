#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<tp> v;
	for (int i = 1; i <= n; ++i)
	{
		int a = i, b = 0;
		cin >> b;
		v.push_back(make_tuple(0, a, b));
	}
	for (auto &[a, _, __] : v)
	{
		cin >> a;
	}
	sort(v.rbegin(), v.rend());
	dsu p(n + 3);
	ll ans = 0;
	for (auto &[co, v1, v2] : v)
	{
		if (p.same(v1, v2))
		{
			ans += co;
			continue;
		}
		p.merge(v1, v2);
	}
	cout << ans;
	return 0;
}
