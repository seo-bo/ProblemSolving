#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 3);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (c & 1)
		{
			c = (b - --a) * c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
	}
	vector<vector<ll>>dist(n + 1, vector<ll>(2, LLONG_MAX));
	dist[0][0] = 0;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(0, 0, 0));
	while (!pq.empty())
	{
		auto [co, cnt, ver] = pq.top();
		pq.pop();
		if (dist[ver][cnt] < co)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			int nxt = (ver <= nv);
			if (dist[nv][nxt] > nc + co)
			{
				dist[nv][nxt] = nc + co;
				pq.push(make_tuple(nc + co, nxt, nv));
			}
		}
	}
	if (dist[n][1] == LLONG_MAX)
	{
		cout << "Dujjonku so expensive T.T";
		return 0;
	}
	cout << dist[n][1];
	return 0;
}