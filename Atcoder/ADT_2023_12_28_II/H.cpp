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
	vector<vector<int>>graph(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		graph[a].push_back(i);
	}
	vector<int>depth(n + 1, -1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		depth[a] = max(depth[a], b);
	}
	vector<int>ans(n + 1);
	function<void(int, int)> dfs = [&](int node, int p)
		{
			p = max(p, depth[node]);
			ans[node] |= (p >= 0);
			for (auto& i : graph[node])
			{
				dfs(i, p - 1);
			}
		};
	dfs(1, -1);
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		res += ans[i];
	}
	cout << res;
	return 0;
}
