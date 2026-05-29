#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

class LCA // https://github.com/seo-bo/Algorithm_templates/blob/main/LCA.cpp
{
private:
	int n, P;
	vector<int> depth;
	vector<long long> dist;
	vector<vector<int>> table;
	vector<vector<pair<int, long long>>> graph;
	void psh(int a, int b, long long w)
	{
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	void dfs(int d, int parent, int node)
	{
		table[0][node] = parent;
		depth[node] = d;
		for (auto &[a, b] : graph[node])
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
	void add_edge(int u, int v, long long w = 1)
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
	int jump(int node, int cnt)
	{
		for (int i = 0; i < P; ++i)
		{
			if (cnt & (1 << i))
			{
				node = table[i][node];
			}
		}
		return node;
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	LCA lca(n + 1);
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		lca.add_edge(a, b);
	}
	lca.init();
	auto bfs = [&](int start)
	{
		vector<int> dist(n + 1, INT_MAX);
		dist[start] = 0;
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto &i : graph[cur])
			{
				if (dist[i] > dist[cur] + 1)
				{
					dist[i] = dist[cur] + 1;
					q.push(i);
				}
			}
		}
		int pivot = 0, idx = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] > pivot)
			{
				pivot = dist[i];
				idx = i;
			}
		}
		return idx;
	};
	int A = bfs(1), B = bfs(A);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, ans = -1;
		cin >> a >> b;
		for (auto &i : {A, B})
		{
			int dist = lca.get_dist(a, i);
			if (dist < b)
			{
				continue;
			}
			int ver = lca.ancestor(a, i), len = lca.get_dist(a, ver);
			if (len >= b)
			{
				ans = lca.jump(a, b);
				break;
			}
			ans = lca.jump(i, dist - b);
			break;
		}
		cout << ans << '\n';
	}
	return 0;
}
