#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<tp> edge(n - 1);
	for (auto &[a, b, c] : edge)
	{
		cin >> b >> c >> a;
	}
	sort(edge.begin(), edge.end());
	dsu p(n + 1);
	ll ans = 0;
	for (auto &[co, v1, v2] : edge)
	{
		ans += co * (ll)p.size(v1) * (ll)p.size(v2);
		p.merge(v1, v2);
	}
	cout << ans;
	return 0;
}
