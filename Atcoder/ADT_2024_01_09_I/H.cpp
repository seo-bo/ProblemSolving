#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>degree(n + 1);
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int>q;
	vector<int>dist(n + 1, INT_MAX);
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 1)
		{
			q.push(i);
			dist[i] = 0;
			break;
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (dist[i] > dist[cur] + 1)
			{
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] % 3 == 1)
		{
			ans.push_back(degree[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
