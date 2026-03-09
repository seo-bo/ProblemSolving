#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int st = 0, ed = 0, k = 0;
	cin >> st >> ed >> k;
	auto dijkstra = [&](int start)
		{
			vector<ll>visited(n + 1, LLONG_MAX);
			visited[start] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, start));
			while (!pq.empty())
			{
				auto [co, ver] = pq.top();
				pq.pop();
				if (visited[ver] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ver])
				{
					if (visited[nv] > co + nc)
					{
						visited[nv] = co + nc;
						pq.push(make_pair(visited[nv], nv));
					}
				}
			}
			return visited;
		};
	vector<ll>A = dijkstra(st), B = dijkstra(ed);
	ll ans = LLONG_MAX;
	for (int i = 0; i < k; ++i)
	{
		int a = 0;
		cin >> a;
		if (A[a] == LLONG_MAX || B[a] == LLONG_MAX)
		{
			continue;
		}
		ans = min(ans, A[a] + B[a]);
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}