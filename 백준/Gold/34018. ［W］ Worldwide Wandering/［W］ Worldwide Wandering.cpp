#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>cost(n + 1);
	vector<vector<pll>>graph(n + 1), rev(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		rev[b].push_back(make_pair(a, c));
	}
	auto bfs = [&](vector<vector<pll>>& G)
		{
			vector<tp>visited(n + 1, make_tuple(LLONG_MAX, LLONG_MAX, LLONG_MAX));
			visited[1] = make_tuple(0, 0, 0);
			queue<int>q;
			q.push(1);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				auto [aa, bb, cc] = visited[cur];
				for (auto& [a, b] : G[cur])
				{
					if (get<0>(visited[a]) > aa + 1)
					{
						visited[a] = make_tuple(aa + 1, b + bb + cost[a], b + cc + cost[a]);
						q.push(a);
					}
					else if (get<0>(visited[a]) == aa + 1)
					{
						get<1>(visited[a]) = min(get<1>(visited[a]), b + bb + cost[a]);
						get<2>(visited[a]) = max(get<2>(visited[a]), b + cc + cost[a]);
					}
				}
			}
			return visited;
		};
	vector<tp>go = bfs(graph);
	vector<tp>back = bfs(rev);
	ll pivot = LLONG_MAX;
	for (int i = 2; i <= n; ++i)
	{
		pivot = min(pivot, get<0>(go[i]) + get<0>(back[i]));
	}
	ll ans1 = LLONG_MAX, ans2 = LLONG_MIN;
	for (int i = 2; i <= n; ++i)
	{
		if (get<0>(go[i]) + get<0>(back[i]) != pivot)
		{
			continue;
		}
		ans1 = min(ans1, get<1>(go[i]) + get<1>(back[i]) - cost[i]);
		ans2 = max(ans2, get<2>(go[i]) + get<2>(back[i]) - cost[i]);
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}