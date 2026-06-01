#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>> graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		graph[0].push_back(make_pair(i, 0));
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	ll ans = 0;
	function<void(int, int, ll)> dfs = [&](int mask, int node, ll sum)
	{
		ans = max(ans, sum);
		for (auto &[nv, nc] : graph[node])
		{
			if (mask & (1 << nv))
			{
				continue;
			}
			dfs(mask | (1 << nv), nv, sum + nc);
		}
	};
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
