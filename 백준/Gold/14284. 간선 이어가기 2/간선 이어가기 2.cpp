#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	vector<int>dist(n + 1, INT_MAX);
	int sx = 0, ex = 0;
	cin >> sx >> ex;
	dist[sx] = 0;
	pq.push(make_pair(0, sx));
	while (!pq.empty())
	{
		auto [co, ve] = pq.top();
		pq.pop();
		if (dist[ve] < co)
		{
			continue;
		}
		for (auto& [nc, nv] : graph[ve])
		{
			if (dist[nv] > dist[ve] + nc)
			{
				dist[nv] = dist[ve] + nc;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	cout << dist[ex];
	return 0;
}