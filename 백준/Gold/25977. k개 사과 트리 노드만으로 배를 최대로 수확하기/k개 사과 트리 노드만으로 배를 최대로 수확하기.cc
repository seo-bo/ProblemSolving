#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>graph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>co(n), bit(n);
	for (auto& i : co)
	{
		cin >> i;
	}
	function<void(int, int, int)> dfs = [&](int mask, int parent, int node)
		{
			if (co[node] == 1)
			{
				mask |= (1 << node);
			}
			bit[node] = mask;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(mask, node, i);
			}
		};
	dfs((co[0] == 1), -1, 0);
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		int cnt = 0, mask = 0, res = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				mask |= bit[j];
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if ((bit[j] & mask) == bit[j])
			{
				cnt += (co[j] == 1);
				res += (co[j] == 2);
			}
		}
		if (cnt > k)
		{
			continue;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}