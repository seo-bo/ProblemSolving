#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, r = 0;
	cin >> n >> r;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int l = 0;
	cin >> l;
	vector<int>cost(n + 1, -1);
	for (int i = 0; i < l; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cost[a] = b;
	}
	vector<int>dp(n + 1, -1);
	function<int(int, int, int)> dfs = [&](int parent, int node, int flag)
		{
			if (cost[node] != -1)
			{
				return dp[node] = cost[node];
			}
			int ok = (flag) ? -1 : INT_MAX;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				if (flag)
				{
					ok = max(ok, dfs(node, i, (flag + 1) % 2));
				}
				else
				{
					ok = min(ok, dfs(node, i, (flag + 1) % 2));
				}
			}
			return dp[node] = ok;
		};
	dfs(0, r, 1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int temp = 0;
		cin >> temp;
		cout << dp[temp] << '\n';
	}
	return 0;
}