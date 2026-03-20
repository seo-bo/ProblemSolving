#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	ll ans = 0;
	function<int(int, int)> dfs = [&](int parent, int node)
		{
			ll now = cost[node], pivot = 0;
			for (auto& [a, b] : graph[node])
			{
				if (a == parent)
				{
					pivot = b;
					continue;
				}
				now += dfs(node, a);
			}
			ans += (now + k - 1) / k * pivot * 2;
			return now;
		};
	dfs(-1, 0);
	cout << ans;
	return 0;
}