#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>ans;
	function<bool(int, int)> dfs = [&](int parent, int node)
		{
			if (node == y)
			{
				ans.push_back(node);
				return true;
			}
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				if (dfs(node, i))
				{
					ans.push_back(node);
					return true;
				}
			}
			return false;
		};
	dfs(0, x);
	int len = ans.size();
	for (int i = len - 1; i >= 0; --i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
