#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

pll op(pll a, pll b)
{
	if (a.first < b.first)
	{
		return a;
	}
	return b;
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
	vector<ll> cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<ll> res(n + 1);
	vector<set<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
		res[a] += cost[b];
		res[b] += cost[a];
	}
	segtree<pll, op, e> seg(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		if (res[i])
		{
			seg.set(i, make_pair(res[i], i));
		}
	}
	ll ans = 0;
	while (1)
	{
		auto [co, idx] = seg.all_prod();
		if (co == LLONG_MAX)
		{
			break;
		}
		ans = max(ans, co);
		for (auto &i : graph[idx])
		{
			res[i] -= cost[idx];
			graph[i].erase(idx);
			ll nxt = (res[i]) ? res[i] : LLONG_MAX;
			seg.set(i, make_pair(nxt, i));
		}
		seg.set(idx, make_pair(LLONG_MAX, LLONG_MAX));
	}
	cout << ans;
	return 0;
}
