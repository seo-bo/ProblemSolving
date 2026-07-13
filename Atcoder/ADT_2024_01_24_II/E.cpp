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
	vector<ll>cost(n + 1);
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			graph[i].push_back(b);
		}
	}
	vector<int>visited(n + 1);
	queue<int>q;
	visited[n] = 1;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += cost[i] * visited[i];
	}
	cout << ans;
	return 0;
}
