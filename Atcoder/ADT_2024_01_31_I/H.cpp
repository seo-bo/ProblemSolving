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
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	set<int>s;
	function<void(int, int, int, int)> dfs = [&](int depth, int parent, int node, int lim)
		{
			if (depth > lim)
			{
				return;
			}
			if (depth <= lim)
			{
				s.insert(node);
			}
			int res = (depth <= lim) * node;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(depth + 1, node, i, lim);
			}
		};
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		dfs(0, 0, a, b);
		ll ans = 0;
		for (auto& i : s)
		{
			ans += i;
		}
		cout << ans << '\n';
		set<int>().swap(s);
	}
	return 0;
}
