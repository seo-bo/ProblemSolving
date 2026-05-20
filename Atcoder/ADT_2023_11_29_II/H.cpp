#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<tp> edge(m);
	for (auto &[co, a, b] : edge)
	{
		cin >> a >> b >> co;
	}
	sort(edge.begin(), edge.end());
	dsu p(n + 1);
	ll ans = 0;
	for (auto &[co, a, b] : edge)
	{
		if (co < 0)
		{
			p.merge(a, b);
			continue;
		}
		if (p.same(a, b))
		{
			ans += co;
		}
		else
		{
			p.merge(a, b);
		}
	}
	cout << ans;
	return 0;
}
