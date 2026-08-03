#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, e = 0;
	cin >> n >> m >> e;
	vector<pii>edge(e + 1);
	for (int i = 1; i <= e; ++i)
	{
		auto& [a, b] = edge[i];
		cin >> a >> b;
	}
	int q = 0;
	cin >> q;
	vector<int>query(q), visited(e + 1);
	for (auto& i : query)
	{
		cin >> i;
		visited[i] = 1;
	}
	int tot = 0;
	vector<int>pos(n + m + 5);
	iota(pos.begin(), pos.end(), 0);
	dsu p(n + m + 5);
	auto cal = [&](int idx)
		{
			auto [a, b] = edge[idx];
			a = pos[p.leader(a)], b = pos[p.leader(b)];
			if (a > b)
			{
				swap(a, b);
			}
			if (p.same(a, b))
			{
				return;
			}
			int alen = p.size(a), blen = p.size(b);
			p.merge(a, b);
			pos[p.leader(b)] = b;
			if (a <= n && b > n)
			{
				tot += alen;
			}
		};
	for (int i = 1; i <= e; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		cal(i);
	}
	vector<int>ans = { tot };
	while (query.size() > 1)
	{
		cal(query.back());
		query.pop_back();
		ans.push_back(tot);
	}
	reverse(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
