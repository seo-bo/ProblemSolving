#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		while (1)
		{
			int a = 0;
			cin >> a;
			if (!a)
			{
				break;
			}
			graph[i].push_back(a);
			degree[a]++;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		degree[i] = (degree[i] + 1) / 2;
	}
	int m = 0;
	cin >> m;
	vector<int>visited(n + 1, INT_MAX);
	queue<int>q;
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		visited[a] = 0;
		q.push(a);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (visited[i] != INT_MAX)
			{
				continue;
			}
			if (!(--degree[i]))
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((visited[i] == INT_MAX) ? -1 : visited[i]) << ' ';
	}
	return 0;
}