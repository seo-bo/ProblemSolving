#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<vector<ll>> dist(n + 1, vector<ll>(1 << n, LLONG_MAX));
	queue<pii> q;
	for (int i = 1; i <= n; ++i)
	{
		int mask = 1 << (i - 1);
		dist[i][mask] = 1;
		q.push(make_pair(i, mask));
	}
	while (!q.empty())
	{
		auto [cur, mask] = q.front();
		q.pop();
		for (auto &i : graph[cur])
		{
			int nxt = mask ^ (1 << (i - 1));
			if (dist[i][nxt] > dist[cur][mask] + 1)
			{
				dist[i][nxt] = dist[cur][mask] + 1;
				q.push(make_pair(i, nxt));
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i < (1 << n); ++i)
	{
		ll temp = LLONG_MAX;
		for (int j = 1; j <= n; ++j)
		{
			temp = min(temp, dist[j][i]);
		}
		ans += ((temp == LLONG_MAX) ? 0 : temp);
	}
	cout << ans;
	return 0;
}
