#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>degree(n + 1);
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	// 사전순;
	vector<int>ans;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1; i <= n; ++i)
	{
		if (!degree[i])
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		ans.push_back(cur);
		for (auto& i : graph[cur])
		{
			if (--degree[i] == 0)
			{
				pq.push(i);
			}
		}
	}
	if (ans.size() != n)
	{
		cout << -1;
		return 0;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
