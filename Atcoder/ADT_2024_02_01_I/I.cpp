#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b)
{
	return min(a, b);
}

ll e()
{
	return LLONG_MAX / 8;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>sp;
	vector<vector<ll>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (!a)
		{
			sp.push_back(b);
			continue;
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	auto bfs = [&](ll start)
		{
			vector<ll>visited(n + 1, LLONG_MAX / 8);
			queue<ll>q;
			q.push(start);
			visited[start] = 0;
			while (!q.empty())
			{
				ll cur = q.front();
				q.pop();
				for (auto& i : graph[cur])
				{
					if (visited[i] > visited[cur] + 1)
					{
						visited[i] = visited[cur] + 1;
						q.push(i);
					}
				}
			}
			return visited;
		};
	vector<ll>d1 = bfs(1), d2 = bfs(n);
	ll base = d1[n];
	segtree<ll, op, e>go(n + 5), rev(n + 5);
	for (auto& i : sp)
	{
		go.set(i, d1[i]);
		rev.set(i, d2[i]);
	}
	for (ll i = 1; i <= n; ++i)
	{
		ll ans = min({ base, d1[i] + rev.all_prod() + 1, d2[i] + go.all_prod() + 1, go.all_prod() + rev.all_prod() + 2 });
		if (ans >= INT_MAX)
		{
			cout << -1 << ' ';
			continue;
		}
		cout << ans << ' ';
	}
	return 0;
}
