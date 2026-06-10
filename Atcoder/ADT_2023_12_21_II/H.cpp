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
		graph[a - 1].push_back(b);
		graph[b].push_back(a - 1);
	}
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(0);
	visited[0] = true;
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
	cout << ((visited[n]) ? "Yes" : "No");
	return 0;
}
