#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
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
	vector<vector<ll>>dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	for (int i = 1; i <= n; ++i)
	{
		dist[i][1] = 0;
		pq.push(make_tuple(0, i, 1));
	}
	while (!pq.empty())
	{
		auto [co, ver, cnt] = pq.top();
		pq.pop();
		if (dist[ver][cnt] < co || cnt == n)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			if (dist[nv][cnt + 1] > nc + co)
			{
				dist[nv][cnt + 1] = nc + co;
				pq.push(make_tuple(nc + co, nv, cnt + 1));
			}
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ans = min(ans, dist[i][n]);
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}