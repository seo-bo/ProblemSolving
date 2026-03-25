#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

class LCA //https://github.com/seo-bo/Algorithm_templates/blob/main/LCA.cpp
{
private:
	int n, P;
	vector<int>depth;
	vector<long long>dist;
	vector<vector<int>>table;
	vector<vector<pair<int, long long>>>graph;
	void psh(int a, int b, long long w)
	{
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	void dfs(int d, int parent, int node)
	{
		table[0][node] = parent;
		depth[node] = d;
		for (auto& [a, b] : graph[node])
		{
			if (a == parent)
			{
				continue;
			}
			dist[a] = dist[node] + b;
			dfs(d + 1, node, a);
		}
	}
	void build(int root)
	{
		dfs(0, 0, root);
		for (int i = 1; i < P; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int mid = table[i - 1][j];
				table[i][j] = table[i - 1][mid];
			}
		}
	}
	int lca(int a, int b)
	{
		if (depth[a] < depth[b])
		{
			swap(a, b);
		}
		int diff = depth[a] - depth[b];
		for (int i = 0; diff; ++i, diff >>= 1)
		{
			if (diff & 1)
			{
				a = table[i][a];
			}
		}
		if (a == b)
		{
			return a;
		}
		for (int i = P - 1; i >= 0; --i)
		{
			if (table[i][a] != table[i][b])
			{
				a = table[i][a];
				b = table[i][b];
			}
		}
		return table[0][a];
	}
	long long distance(int a, int b)
	{
		return dist[a] + dist[b] - 2 * dist[lca(a, b)];
	}
public:
	LCA(int len)
	{
		n = len, P = 20;
		depth.resize(n + 1, 0);
		table.resize(P, vector<int>(n + 1));
		dist.resize(n + 1, 0);
		graph.resize(n + 1);
	}
	void add_edge(int u, int v, long long w = 0)
	{
		psh(u, v, w);
	}
	void init(int root = 1)
	{
		build(root);
	}
	int ancestor(int u, int v)
	{
		return lca(u, v);
	}
	long long get_dist(int u, int v)
	{
		return distance(u, v);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1), rank(n + 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (rank[r1] < rank[r2])
			{
				swap(r1, r2);
			}
			parent[r2] = r1;
			rank[r1] += (rank[r1] == rank[r2]);
		};
	vector<vector<pll>>graph(n + 1);
	vector<tp>edge(m);
	for (auto& [co, v1, v2] : edge)
	{
		cin >> v1 >> v2 >> co;
		graph[v1].push_back(make_pair(v2, co));
		graph[v2].push_back(make_pair(v1, co));
	}
	vector<int>v;
	sort(edge.begin(), edge.end());
	LCA lca(n + 1);
	for (int i = 0, cnt = 0; i < m; ++i)
	{
		auto [co, v1, v2] = edge[i];
		if (find(v1) != find(v2) && cnt < n - 1)
		{
			merge(v1, v2);
			lca.add_edge(v1, v2, co);
			cnt++;
		}
		else
		{
			v.push_back(v1), v.push_back(v2);
		}
	}
	lca.init();
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<vector<ll>>dist;
	auto dijkstra = [&](int start)
		{
			vector<ll>d(n + 1, LLONG_MAX);
			d[start] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, start));
			while (!pq.empty())
			{
				auto [co, ver] = pq.top();
				pq.pop();
				if (d[ver] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ver])
				{
					if (d[nv] > nc + co)
					{
						d[nv] = nc + co;
						pq.push(make_pair(d[nv], nv));
					}
				}
			}
			dist.push_back(d);
		};
	for (auto& i : v)
	{
		dijkstra(i);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		ll ans = lca.get_dist(a, b);
		for (auto& i : dist)
		{
			if (i[a] == LLONG_MAX || i[b] == LLONG_MAX)
			{
				continue;
			}
			ans = min(ans, i[a] + i[b]);
		}
		cout << ans << '\n';
	}
	return 0;
}