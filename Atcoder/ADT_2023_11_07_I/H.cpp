#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1), rank(n + 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (rank[r1] < rank[r2])
			{
				swap(r1, r2);
			}
			parent[r2] = r1;
			rank[r1] += (rank[r1] == rank[r2]);
		};
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>ans(n + 1);
	int cnt = 0;
	for (int i = n; i >= 1; --i)
	{
		ans[i] = cnt++;
		for (auto& j : graph[i])
		{
			if (j > i && find(i) != find(j))
			{
				merge(i, j);
				cnt--;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
