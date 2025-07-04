#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;

class DSU //https://github.com/seo-bo/Algorithm_templates/blob/main/DSU.cpp
{
private:
	int n;
	vector<int>parent, rank;
	int get_path(int root)
	{
		return (parent[root] == root) ? parent[root] : parent[root] = get_path(parent[root]);
	}
	void merger(int root1, int root2)
	{
		int r1 = get_path(root1), r2 = get_path(root2);
		if (r1 != r2)
		{
			if (rank[r1] > rank[r2])
			{
				parent[r2] = r1;
			}
			else
			{
				parent[r1] = r2;
				if (rank[r1] == rank[r2])
				{
					rank[r2]++;
				}
			}
		}
	}
public:
	DSU(int ok)
	{
		n = ok;
		parent.resize(n + 1, 0);
		rank.resize(n + 1, 0);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int root)
	{
		return get_path(root);
	}
	void merge(int root1, int root2)
	{
		merger(root1, root2);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<vector<pll>>graph(n + 1);
	vector<vector<int>>vers(n + 1);
	vector<ll>degree(n + 1), color(n + 1, -1);
	for (ll i = 0; i < n - 1; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
		vers[a].push_back(b);
		vers[b].push_back(a);
		if (++degree[a] == n - 1 || ++degree[b] == n - 1)
		{
			cout << -1;
			return 0;
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
		sort(vers[i].begin(), vers[i].end());
	}
	color[1] = 0;
	queue<ll>q;
	vector<vector<ll>>bi(2);
	bi[0].push_back(1);
	q.push(1);
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		for (auto& [_, i] : graph[cur])
		{
			if (color[i] == -1)
			{
				color[i] = (color[cur] + 1) % 2;
				bi[color[i]].push_back(i);
				q.push(i);
			}
		}
	}
	vector<vector<pll>>dp(n + 1);
	set<tp>ok;
	for (ll i = 0; i < 2; ++i)
	{
		for (auto& j : bi[i])
		{
			for (auto& [ac, av] : graph[j])
			{
				for (auto& [bc, bv] : graph[j])
				{
					if (av == bv)
					{
						continue;
					}
					dp[av].push_back(make_pair(ac + bc, bv));
					ll a = min(av, bv), b = max(av, bv);
					ok.insert(make_tuple(ac + bc, a, b));
					break;
				}
			}
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		sort(dp[i].begin(), dp[i].end());
		for (auto& [cc, vv] : graph[i])
		{
			for (auto& [nc, nv] : dp[i])
			{
				if (!binary_search(vers[nv].begin(), vers[nv].end(), vv))
				{
					ll aa = min(nv, vv);
					ll bb = max(nv, vv);
					ok.insert(make_tuple(nc + cc, aa, bb));
					break;
				}
			}
		}
	}
	ll ans = 0, e = 0;
	DSU dsu(n);
	for (auto it = ok.begin(); it != ok.end() && e < n - 1; ++it)
	{
		auto& [a, b, c] = *it;
		if (dsu.find(b) != dsu.find(c))
		{
			dsu.merge(b, c);
			ans += a;
			e++;
		}
	}
	cout << ans;
	return 0;
}