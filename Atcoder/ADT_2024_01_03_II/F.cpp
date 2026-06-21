#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, s = 0, e = 0;
	cin >> n >> s >> e;
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
			if (node == e)
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
	dfs(0, s);
	reverse(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
