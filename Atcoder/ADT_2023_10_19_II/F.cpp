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
	set<int>s;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		s.insert(find(i));
	}
	cout << s.size();
	return 0;
}
