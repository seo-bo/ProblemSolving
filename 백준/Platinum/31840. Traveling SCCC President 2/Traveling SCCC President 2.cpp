#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	auto bfs = [&](ll p) -> bool
		{
			vector<bool>visited(n + 1, false);
			visited[1] = true;
			queue<ll>q;
			q.push(1);
			while (!q.empty())
			{
				ll cur = q.front();
				q.pop();
				for (auto& [a, b] : graph[cur])
				{
					if ((b & p) == 0 && !visited[a])
					{
						visited[a] = true;
						q.push(a);
					}
				}
			}
			return visited[n];
		};
	ll ans = 0;
	for (ll i = 60; i >= 0; --i)
	{
		if (!bfs(~(ans | ((1LL << i) - 1))))
		{
			ans |= (1LL << i);
		}
	}
	cout << ans;
	return 0;
}