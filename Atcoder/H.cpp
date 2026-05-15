#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, A = 0, B = 0, C = 0;
	cin >> n >> A >> B >> C;
	vector<vector<pll>> graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a = 0;
			cin >> a;
			if (!a)
			{
				continue;
			}
			graph[i].push_back(make_pair(j, a));
		}
	}
	auto dijkstra = [&](int start, ll a, ll b)
	{
		vector<ll> dist(n + 1, LLONG_MAX);
		dist[start] = 0;
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push(make_pair(0, start));
		while (!pq.empty())
		{
			auto [co, ver] = pq.top();
			pq.pop();
			if (dist[ver] < co)
			{
				continue;
			}
			for (auto &[nv, nc] : graph[ver])
			{
				if (dist[nv] > co + nc * a + b)
				{
					dist[nv] = co + nc * a + b;
					pq.push(make_pair(dist[nv], nv));
				}
			}
		}
		return dist;
	};
	vector<ll> car = dijkstra(1, A, 0), densha = dijkstra(n, B, C);
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ans = min(ans, car[i] + densha[i]);
	}
	cout << ans;
	return 0;
}
