#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int node, int mask, int sum)
		{
			ans = max(ans, sum);
			for (auto& [nv, nc] : graph[node])
			{
				if (mask & (1 << nv))
				{
					continue;
				}
				dfs(nv, mask | (1 << nv), sum + nc);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		dfs(i, (1 << i), 0);
	}
	cout << ans;
	return 0;
}

