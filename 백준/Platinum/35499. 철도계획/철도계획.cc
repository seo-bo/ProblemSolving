#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<tp>edge(m);
	for (auto& [a, b, c] : edge)
	{
		cin >> b >> c >> a;
	}
	sort(edge.rbegin(), edge.rend());
	vector<int>cycle(n + 1), parent(n + 1), rank(n + 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			int f = cycle[r1] + cycle[r2];
			if (f == 2)
			{
				return false;
			}
			if ((f && cycle[r2]) || ((!f && rank[r1] < rank[r2])))
			{
				swap(r1, r2);
			}
			cycle[r1] |= (r1 == r2), parent[r2] = r1, rank[r1] += (rank[r1] == rank[r2]);
			return true;
		};
	ll ans = 0;
	for (auto& [co, v1, v2] : edge)
	{
		if (merge(v1, v2))
		{
			ans += co;
		}
	}
	cout << ans;
	return 0;
}