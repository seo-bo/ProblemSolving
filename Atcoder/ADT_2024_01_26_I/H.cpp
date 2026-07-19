#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

pll op(pll a, pll b)
{
	return (a.first < b.first) ? a : b;
}

pll e()
{
	return make_pair(LLONG_MAX, LLONG_MAX);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	segtree<pll, op, e>seg(n + 5);
	vector<set<int>>graph(n + 1);
	vector<ll>cost(n + 1), sum(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
		sum[a] += cost[b];
		sum[b] += cost[a];
	}
	for (int i = 1; i <= n; ++i)
	{
		seg.set(i, make_pair(sum[i], i));
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		auto [nc, nv] = seg.all_prod();
		ans = max(ans, nc);
		for (auto& j : graph[nv])
		{
			sum[j] -= cost[nv];
			graph[j].erase(nv);
			seg.set(j, make_pair(sum[j], j));
		}
		seg.set(nv, e());
	}
	cout << ans;
	return 0;
}
