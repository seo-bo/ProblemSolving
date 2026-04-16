#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<vector<int>>save(n + 1);
	function<void(int, int)> dfs = [&](int parent, int node)
		{
			vector<int>temp = { v[node] };
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(node, i);
				for (auto& j : save[i])
				{
					temp.push_back(j);
				}
			}
			sort(temp.rbegin(), temp.rend());
			for (int i = 0; i < min((int)temp.size(), 20); ++i)
			{
				save[node].push_back(temp[i]);
			}
		};
	dfs(0, 1);
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << save[a][b - 1] << '\n';
	}
	return 0;
}
