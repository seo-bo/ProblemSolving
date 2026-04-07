#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	while (cin >> n)
	{
		cin >> m;
		vector<vector<pii>>graph(n + 1);
		for (int i = 0; i < n - 1; ++i)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		function<int(int, int)> dfs = [&](int parent, int node)
			{
				int temp = 0;
				for (auto& [nv, nc] : graph[node])
				{
					if (nv == parent)
					{
						continue;
					}
					temp += min(nc, dfs(node, nv));
				}
				return (temp) ? temp : (1 << 25);
			};
		cout << dfs(0, m) << '\n';
	}
	return 0;
}