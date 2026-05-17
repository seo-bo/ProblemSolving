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
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	{
		vector<bool> visited(n + 1);
		function<void(int)> dfs = [&](int node)
		{
			visited[node] = true;
			for (auto &i : graph[node])
			{
				if (visited[i])
				{
					continue;
				}
				cout << node << ' ' << i << '\n';
				dfs(i);
			}
		};
		dfs(1);
	}
	{
		vector<bool> visited(n + 1);
		queue<int> q;
		q.push(1);
		visited[1] = true;
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
					cout << cur << ' ' << i << '\n';
				}
			}
		}
	}
	return 0;
}
