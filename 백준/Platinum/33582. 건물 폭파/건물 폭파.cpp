#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<ll>cost(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<ll>dp(n + 1);
	function<ll(int, int)> dfs = [&](int parent, int node)
		{
			ll temp = cost[node];
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				temp = max(temp, dfs(node, i) + 1);
			}
			return dp[node] = temp;
		};
	dfs(0, 1);
	ll ans = LLONG_MAX;
	function<void(int, int, ll)> ok = [&](int parent, int node, ll value)
		{
			ans = min(ans, max({ cost[node], value, dp[node] }));
			vector<pll>temp = { {max(value + 1,cost[node] + 1),0} }; // 내릴거 생각
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				temp.push_back(make_pair(dp[i] + 2, i));
			}
			sort(temp.rbegin(), temp.rend());
			auto [a, b] = temp[0];
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				if (i == b)
				{
					auto [c, d] = temp[1];
					ok(node, i, c);
				}
				else
				{
					ok(node, i, a);
				}
			}
		};
	ok(0, 1, 0LL);
	cout << ans;
	return 0;
}