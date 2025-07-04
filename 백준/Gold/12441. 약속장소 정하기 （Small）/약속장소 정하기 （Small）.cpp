#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		int n = 0, p = 0, m = 0;
		cin >> n >> p >> m;
		vector<vector<ll>>dist(p + 1, vector<ll>(n + 1, LLONG_MAX));
		vector<pll>coco(p + 1);
		for (int i = 1; i <= p; ++i)
		{
			auto& [a, b] = coco[i];
			cin >> a >> b;
		}
		vector<vector<pll>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			int pre = 0;
			cin >> pre;
			for (int j = 0; j < b - 1; ++j)
			{
				int c = 0;
				cin >> c;
				graph[pre].push_back(make_pair(c, a));
				graph[c].push_back(make_pair(pre, a));
				pre = c;
			}
		}
		auto dijkstra = [&](int num, int st, ll cost)
			{
				dist[num][st] = 0;
				priority_queue<pll, vector<pll>, greater<pll>>pq;
				pq.push(make_pair(0, st));
				while (!pq.empty())
				{
					auto [co, ver] = pq.top();
					pq.pop();
					if (dist[num][ver] < co)
					{
						continue;
					}
					for (auto& [nv, nc] : graph[ver])
					{
						if (dist[num][nv] > dist[num][ver] + nc * cost)
						{
							dist[num][nv] = dist[num][ver] + nc * cost;
							pq.push(make_pair(dist[num][nv], nv));
						}
					}
				}
			};
		for (int i = 1; i <= p; ++i)
		{
			auto [a, b] = coco[i];
			dijkstra(i, a, b);
		}
		ll ans = LLONG_MAX;
		for (int i = 1; i <= n; ++i)
		{
			ll temp = LLONG_MIN;
			for (int j = 1; j <= p; ++j)
			{
				temp = max(temp, dist[j][i]);
			}
			ans = min(ans, temp);
		}
		cout << format("Case #{}: {}\n", _, (ans == LLONG_MAX) ? -1 : ans);
	}
	return 0;
}