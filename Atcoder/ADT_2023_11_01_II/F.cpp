#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		graph[i].push_back(a);
	}
	vector<bool>visited(n + 1);
	vector<int>ans;
	int pivot = -1;
	function<bool(int)> dfs = [&](int node)
		{
			visited[node] = true;
			for (auto& i : graph[node])
			{
				if (visited[i] == true)
				{
					pivot = i;
					ans.push_back(node);
					return true;
				}
				if (dfs(i))
				{
					ans.push_back(node);
					return (node != pivot);
				}
			}
			return false;
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
			if (!ans.empty())
			{
				reverse(ans.begin(), ans.end());
				cout << ans.size() << '\n';
				for (auto& i : ans)
				{
					cout << i << ' ';
				}
				return 0;
			}
		}
	}
	return 0;
}
