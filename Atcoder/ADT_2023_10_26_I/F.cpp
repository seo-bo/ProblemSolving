#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<ll>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> cost[i] >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			graph[i].push_back(b);
		}
	}
	vector<bool>visited(n + 1);
	function<void(int)> dfs = [&](int node)
		{
			if (visited[node])
			{
				return;
			}
			visited[node] = true;
			for (auto& i : graph[node])
			{
				dfs(i);
			}
		};
	dfs(n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += ((visited[i]) ? cost[i] : 0);
	}
	cout << ans;
	return 0;
}
