#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<int> parent(n + 1), rank(n + 1);
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
	vector<vector<pii>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (find(a) != find(b))
		{
			merge(a, b);
		}
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, -c));
	}
	vector<bool> ban(n + 1);
	vector<ll> dist(n + 1, LLONG_MAX);
	for (int i = 1; i <= n; ++i)
	{
		int p = find(i);
		if (dist[p] != LLONG_MAX)
		{
			continue;
		}
		queue<int> q;
		q.push(p);
		dist[p] = 0;
		while (!q.empty() && !ban[p])
		{
			int cur = q.front();
			q.pop();
			for (auto &[nv, nc] : graph[cur])
			{
				if (dist[nv] == LLONG_MAX)
				{
					dist[nv] = dist[cur] + nc;
					q.push(nv);
					continue;
				}
				if (dist[nv] != dist[cur] + nc)
				{
					ban[p] = true;
					break;
				}
			}
		}
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			cout << "nan\n";
			continue;
		}
		if (ban[find(a)])
		{
			cout << "inf\n";
			continue;
		}
		cout << dist[b] - dist[a] << '\n';
	}
	return 0;
}
