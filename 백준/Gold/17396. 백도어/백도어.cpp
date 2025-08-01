#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<bool>ban(n, false);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		ban[i] = (temp == 1);
	}
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<ll>dist(n, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 0));
	dist[0] = 0;
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
			if (nv != n - 1 && ban[nv])
			{
				continue;
			}
			if (dist[nv] > dist[ver] + nc)
			{
				dist[nv] = dist[ver] + nc;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	cout << ((dist[n - 1] == LLONG_MAX) ? -1 : dist[n - 1]);
	return 0;
}