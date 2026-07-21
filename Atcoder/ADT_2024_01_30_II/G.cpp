#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, cnt = 1;
	cin >> n;
	map<string, int>mm;
	vector<vector<int>>graph(2 * n + 1);
	vector<int>degree(2 * n + 1);
	for (int i = 0; i < n; ++i)
	{
		string s, t;
		cin >> s >> t;
		int a = 0, b = 0;
		if (mm.find(s) == mm.end())
		{
			a = cnt;
			mm[s] = cnt++;
		}
		else
		{
			a = mm[s];
		}
		if (mm.find(t) == mm.end())
		{
			b = cnt;
			mm[t] = cnt++;
		}
		else
		{
			b = mm[t];
		}
		graph[a].push_back(b);
		degree[b]++;
	}
	vector<int>visited(2 * n + 1);
	queue<int>q;
	for (int i = 1; i <= 2 * n; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
			visited[i] = 1;
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (--degree[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	for (int i = 1; i <= 2 * n; ++i)
	{
		if (!visited[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
