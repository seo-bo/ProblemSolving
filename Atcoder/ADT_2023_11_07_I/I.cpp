#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		pos[v[i]] = i;
	}
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
	int m = 0;
	cin >> m;
	vector<pii>edge(m + 1);
	vector<vector<pii>>graph(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		auto& [a, b] = edge[i];
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
			graph[a].push_back(make_pair(i, b));
			graph[b].push_back(make_pair(i, a));
		}
	}
	vector<vector<int>>par(n + 1, vector<int>(n + 1, -1));
	auto bfs = [&](int start)
		{
			vector<bool>visited(n + 1);
			queue<int>q;
			q.push(start);
			visited[start] = true;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& [a, b] : graph[cur])
				{
					if (!visited[b])
					{
						visited[b] = true;
						par[start][b] = a;
						q.push(b);
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		bfs(i);
	}
	vector<int>depth(n + 1), ok(n);
	iota(ok.begin(), ok.end(), 1);
	for (int i = 1; i <= n; ++i)
	{
		if (depth[i])
		{
			continue;
		}
		queue<int>q;
		q.push(i);
		depth[i] = 1;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto& [a, b] : graph[cur])
			{
				if (!depth[b])
				{
					depth[b] = depth[cur] + 1;
					q.push(b);
				}
			}
		}
	}
	sort(ok.begin(), ok.end(), [&](const int& a, const int& b)
		{
			return depth[a] > depth[b];
		});
	vector<int>ans;
	for (auto& i : ok)
	{
		int now = pos[i];
		while (par[i][now] != -1)
		{
			int p = par[i][now];
			auto [pa, pb] = edge[p];
			int a = v[pa], b = v[pb];
			if (pa != now)
			{
				swap(pa, pb);
				swap(a, b);
			}
			swap(pos[a], pos[b]), swap(v[pa], v[pb]);
			ans.push_back(p);
			now = pb;
		}
		if (now != i)
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
