#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1), rev(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			if (a == '1')
			{
				graph[i].push_back(i + j);
				rev[i + j].push_back(i);
			}
		}
	}
	auto bfs = [&](int start, vector<vector<int>> &g)
	{
		queue<int> q;
		vector<ll> visited(n + 1, INT_MAX);
		visited[start] = 0;
		q.push(start);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto &i : g[cur])
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
	vector<ll> go = bfs(1, graph), back = bfs(n, rev);
	for (int i = 2; i <= n - 1; ++i)
	{
		ll temp = INT_MAX;
		for (int j = 1; j <= m && i - j >= 1; ++j)
		{
			int pre = i - j;
			for (auto &k : graph[pre])
			{
				if (k <= i)
				{
					continue;
				}
				temp = min(temp, go[pre] + back[k] + 1);
			}
		}
		cout << ((temp == INT_MAX) ? -1 : temp) << ' ';
	}
	return 0;
}
