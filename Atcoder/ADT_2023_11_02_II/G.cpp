#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (auto& i : graph)
	{
		sort(i.begin(), i.end());
	}
	function<void(int, int)> dfs = [&](int parent, int node)
		{
			cout << node << ' ';
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(node, i);
				cout << node << ' ';
			}
		};
	dfs(0, 1);
	return 0;
}
