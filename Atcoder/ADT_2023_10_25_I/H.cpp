#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<pii>ans(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int cnt = 1;
	function<pii(int, int)> dfs = [&](int node, int parent)
		{
			int left = INT_MAX, right = INT_MIN;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				auto [a, b] = dfs(i, node);
				left = min(left, a), right = max(right, b);
			}
			if (left == INT_MAX)
			{
				left = right = cnt++;
			}
			return ans[node] = make_pair(left, right);
		};
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = ans[i];
		cout << a << ' ' << b << '\n';
	}
	return 0;
}
