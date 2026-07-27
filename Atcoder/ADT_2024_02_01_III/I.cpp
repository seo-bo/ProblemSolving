#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
	vector<ll>siz(n + 1), ans(n + 1);
	function<ll(int, int)> dfs = [&](int parent, int node)
		{
			ll temp = 1;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				temp += dfs(node, i);
			}
			ans[1] += temp;
			return siz[node] = temp;
		};
	dfs(0, 1);
	ans[1] -= siz[1];
	function<void(int, int)> res = [&](int parent, int node)
		{
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				/*
				내부정점은 siz[i]만큼 있는데 i로 가면 거리가 1씩 줄어드므로 -siz[i]
				외부 정점은 n - siz[i]만큼 있는데 i로 가면 거리가 1씩 늘어나므로 + n - siz[i]
				*/
				ans[i] = ans[node] - siz[i] + n - siz[i];
				res(node, i);
			}
		};
	res(0, 1);
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
