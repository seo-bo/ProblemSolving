#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, y = 0;
	cin >> n >> m >> y;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		graph[i].push_back(make_pair(0, a + y));
		graph[0].push_back(make_pair(i, a));
	}
	vector<ll>dist(n + 1, LLONG_MAX);
	dist[1] = 0;
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [co, ver] = pq.top();
		pq.pop();
		if (dist[ver] < co)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			if (dist[nv] > dist[ver] + nc)
			{
				dist[nv] = dist[ver] + nc;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		cout << dist[i] << ' ';
	}
	return 0;
}
