#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1), rev(n + 1);
	vector<int>degree(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			graph[b].push_back(i);
			rev[i].push_back(b);
			degree[i]++;
		}
	}
	vector<int>visited(n + 1);
	{
		queue<int>q;
		q.push(1);
		visited[1] = 1;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto& i : rev[cur])
			{
				if (!visited[i])
				{
					visited[i] = 1;
					q.push(i);
				}
			}
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (!degree[i] && visited[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == 1)
		{
			break;
		}
		cout << cur << ' ';
		for (auto& i : graph[cur])
		{
			if (--degree[i] == 0 && visited[i])
			{
				q.push(i);
			}
		}
	}
	return 0;
}
