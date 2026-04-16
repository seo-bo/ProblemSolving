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
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<vector<ll>>dist(n + 1, vector<ll>(2, LLONG_MAX));
	dist[1][0] = 0;
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [co, ver] = pq.top();
		pq.pop();
		if (dist[ver][co % 2] < co)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			ll nxt = (nc + co) % 2;
			if (dist[nv][nxt] > co + nc)
			{
				dist[nv][nxt] = co + nc;
				pq.push(make_pair(co + nc, nv));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j >= 0; --j)
		{
			cout << ((dist[i][j] == LLONG_MAX) ? -1 : dist[i][j]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}