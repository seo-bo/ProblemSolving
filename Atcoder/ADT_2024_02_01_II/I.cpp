#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	dsu p(2 * n + 10);
	vector<vector<pll>>graph(2 * n + 10);
	vector<int>root(n + 1);
	iota(root.begin(), root.end(), 0);
	auto power = [&](ll base)
		{
			ll res = 1, exp = MOD - 2;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	int cnt = n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a = p.leader(a), b = p.leader(b);
		ll alen = p.size(a), blen = p.size(b);
		int nxt = ++cnt;
		graph[nxt].push_back(make_pair(root[a], alen * power(alen + blen) % MOD));
		graph[nxt].push_back(make_pair(root[b], blen * power(alen + blen) % MOD));
		root[p.merge(a, b)] = nxt;
	}
	int start = root[p.leader(1)];
	vector<ll>ans(2 * n + 15);
	function<void(int, int, ll)> dfs = [&](int parent, int node, ll sum)
		{
			ans[node] = sum;
			for (auto& [nv, nc] : graph[node])
			{
				if (nv == parent)
				{
					continue;
				}
				dfs(node, nv, (sum + nc) % MOD);
			}
		};
	dfs(0, start, 0);
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
