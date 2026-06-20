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
	int ans = 0;
	vector<int>visited(n + 1);
	function<void(int)> dfs = [&](int node)
		{
			if (++ans == 1000000)
			{
				cout << 1000000;
				exit(0);
			}
			for (auto& i : graph[node])
			{
				if (visited[i])
				{
					continue;
				}
				visited[i] = 1;
				dfs(i);
				visited[i] = 0;
			}
		};
	visited[1] = 1;
	dfs(1);
	cout << ans;
	return 0;
}
