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
	vector<int> degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> ans(n + 1);
	int cnt = 1;
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
		ans[cnt++] = cur;
		for (auto &i : graph[cur])
		{
			if (--degree[i] == 0)
			{
				pq.push(i);
			}
		}
	}
	if (cnt <= n)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i < cnt; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
