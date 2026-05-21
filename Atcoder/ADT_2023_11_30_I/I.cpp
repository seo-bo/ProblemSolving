#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	scc_graph scc(n + 1);
	vector<vector<int>> G(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		G[a].push_back(b);
		scc.add_edge(a, b);
	}
	vector<vector<int>> pivot = scc.scc();
	int len = pivot.size();
	vector<int> id(n + 1), siz(len + 1);
	for (int i = 1; i <= len; ++i)
	{
		for (auto &j : pivot[i - 1])
		{
			id[j] = i;
			siz[i]++;
		}
	}
	vector<vector<int>> graph(len + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (auto &j : G[i])
		{
			if (id[j] != id[i])
			{
				graph[id[j]].push_back(id[i]);
			}
		}
	}
	vector<bool> visited(len + 1);
	queue<int> q;
	for (int i = 1; i <= len; ++i)
	{
		if (siz[i] >= 2)
		{
			visited[i] = true;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= len; ++i)
	{
		if (visited[i])
		{
			ans += siz[i];
		}
	}
	cout << ans;
	return 0;
}
