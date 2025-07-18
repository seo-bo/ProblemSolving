#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, c = 0;
	cin >> n >> m >> c;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	vector<vector<ll>>dist(c + 1, vector<ll>(n + 1, LLONG_MAX));
	dist[0][1] = 0;
	pq.push(make_pair(0, 1));
	auto dijkstra = [&](int pivot)
		{
			while (!pq.empty())
			{
				auto [co, ve] = pq.top();
				pq.pop();
				if (dist[pivot][ve] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ve])
				{
					if (dist[pivot][nv] > dist[pivot][ve] + nc)
					{
						dist[pivot][nv] = dist[pivot][ve] + nc;
						pq.push(make_pair(dist[pivot][nv], nv));
					}
				}
			}
		};
	dijkstra(0);
	ll ans = dist[0][n];
	for (int i = 1; i <= c; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i - 1][j] == LLONG_MAX)
			{
				continue;
			}
			for (auto& [nv, nc] : graph[j])
			{
				dist[i][nv] = min(dist[i][nv], dist[i - 1][j] - nc);
			}
		}
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] == LLONG_MAX)
			{
				continue;
			}
			pq.push(make_pair(dist[i][j], j));
		}
		dijkstra(i);
		ans = min(ans, dist[i][n]);
	}
	cout << ans;
	return 0;
}