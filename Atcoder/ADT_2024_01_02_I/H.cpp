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
	vector<int> degree(n + 1), ans(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (!degree[i])
		{
			ans[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : graph[cur])
		{
			if (--degree[i] == 0)
			{
				ans[i] = ans[cur] + 1;
				q.push(i);
			}
		}
	}
	set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		if (!ans[i])
		{
			cout << "No";
			return 0;
		}
		s.insert(ans[i]);
	}
	if (s.size() != n)
	{
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
