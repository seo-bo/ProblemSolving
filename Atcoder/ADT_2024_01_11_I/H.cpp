#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<tp>>graph(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_tuple(b, c, i));
		graph[b].push_back(make_tuple(a, c, i));
	}
	vector<ll>dist(n + 1, LLONG_MAX), save(n + 1, -1);
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
		for (auto& [nv, nc, num] : graph[ver])
		{
			if (dist[nv] > co + nc)
			{
				dist[nv] = co + nc;
				save[nv] = num;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		cout << save[i] << ' ';
	}
	return 0;
}
