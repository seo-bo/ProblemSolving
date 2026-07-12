#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>h(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (h[a] < h[b])
		{
			swap(a, b);
		}
		graph[a].push_back(make_pair(b, 0));
		graph[b].push_back(make_pair(a, h[a] - h[b]));
	}
	vector<ll>dist(n + 1, LLONG_MAX / 8);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
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
			if (dist[nv] > co + nc)
			{
				dist[nv] = co + nc;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	ll ans = 0;
	for (int i = 2; i <= n; ++i)
	{
		ans = max(ans, h[1] - h[i] - dist[i]);
	}
	cout << ans;
	return 0;
}
