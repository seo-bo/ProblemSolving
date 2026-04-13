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
	for (int i = 1; i <= n; ++i)
	{
		cin >> rank[i];
	}
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b, int f)
		{
			int r1 = find(a), r2 = find(b);
			if (rank[r1] < rank[r2])
			{
				swap(r1, r2);
			}
			int p = min(rank[r1], rank[r2]);
			parent[r2] = r1, rank[r2] -= p, rank[r1] = (rank[r1] + (f ? -p : p));
		};
	while (m--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		merge(b, c, a - 1);
	}
	set<int>s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(find(i));
	}
	vector<int>ans;
	for (auto& i : s)
	{
		if (rank[i])
		{
			ans.push_back(rank[i]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}