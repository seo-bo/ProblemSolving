#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, e = 0;
	cin >> n >> m >> e;
	int p = n + m;
	vector<int>parent(p + 3), rank(p + 3, 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			int f1 = (r1 > n), f2 = (r2 > n);
			if (!f1 && f2)
			{
				swap(r1, r2);
			}
			else if (f1 == f2 && rank[r1] < rank[r2])
			{
				swap(r1, r2);
			}
			parent[r2] = r1;
			rank[r1] += rank[r2];
			rank[r2] = 0;
		};
	iota(parent.begin(), parent.end(), 0);
	for (int i = 1; i <= n; ++i)
	{
		rank[i] = 1;
	}
	vector<pii>edge(e);
	for (auto& [a, b] : edge)
	{
		cin >> a >> b;
	}
	int q = 0;
	cin >> q;
	vector<bool>ban(e + 1);
	vector<int>query(q);
	for (auto& i : query)
	{
		cin >> i;
		ban[i - 1] = true;
	}
	for (int i = 0; i < e; ++i)
	{
		if (ban[i])
		{
			continue;
		}
		auto& [a, b] = edge[i];
		if (find(a) != find(b))
		{
			merge(a, b);
		}
	}
	set<int>s;
	for (int i = 1; i <= p; ++i)
	{
		int r = find(i);
		if (r <= n)
		{
			continue;
		}
		s.insert(r);
	}
	vector<int>ans;
	int res = 0;
	for (auto& i : s)
	{
		res += rank[i];
	}
	ans.push_back(res);
	while (!query.empty())
	{
		ans.push_back(res);
		auto& [a, b] = edge[query.back() - 1];
		query.pop_back();
		if (find(a) == find(b))
		{
			continue;
		}
		for (auto& i : { a, b })
		{
			if (find(i) <= n)
			{
				continue;
			}
			res -= rank[find(i)];
		}
		merge(a, b);
		if (find(a) > n)
		{
			res += rank[find(a)];
		}
	}
	while (ans.size() > 1)
	{
		cout << ans.back() << '\n';
		ans.pop_back();
	}
	return 0;
}
