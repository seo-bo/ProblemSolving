#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pll>> graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<ll> d(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}
	vector<vector<pll>> down(n + 1);
	function<void(int, int)> dfs = [&](int parent, int node)
	{
		vector<pll> temp = {make_pair(d[node], node)};
		for (auto &[a, b] : graph[node])
		{
			if (a == parent)
			{
				continue;
			}
			dfs(node, a);
			temp.push_back(make_pair(down[a][0].first + b, a));
		}
		sort(temp.rbegin(), temp.rend());
		while (temp.size() > 2)
		{
			temp.pop_back();
		}
		down[node] = temp;
	};
	dfs(0, 1);
	vector<ll> ans(n + 1);
	function<void(int, int, pll)> dfs2 = [&](int parent, int node, pll pivot)
	{
		ans[node] = pivot.first;
		for (auto &[a, b] : down[node])
		{
			if (b == node)
			{
				continue;
			}
			ans[node] = max(ans[node], a);
		}
		for (auto &[a, b] : graph[node])
		{
			if (a == parent)
			{
				continue;
			}
			pll nxt = make_pair(d[node], node);
			nxt = max(nxt, pivot);
			for (auto &i : down[node])
			{
				if (i.second == a)
				{
					continue;
				}
				nxt = max(nxt, i);
			}
			nxt.first += b;
			dfs2(node, a, nxt);
		}
	};
	dfs2(0, 1, make_pair(0, 0));
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
