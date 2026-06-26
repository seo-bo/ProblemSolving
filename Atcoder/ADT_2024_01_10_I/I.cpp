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
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++, degree[b]++;
	}
	dsu p(n + 2);
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 1)
		{
			q.push(i);
			degree[i]--;
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			p.merge(cur, i);
			if (--degree[i] == 1)
			{
				q.push(i);
			}
		}
	}
	int Q = 0;
	cin >> Q;
	while (Q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << ((p.same(a, b)) ? "Yes\n" : "No\n");
	}
	return 0;
}
