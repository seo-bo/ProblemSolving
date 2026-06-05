#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[2005][2005][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, m = 0, k = 0, s = 0, t = 0, x = 0;
	cin >> n >> m >> k >> s >> t >> x;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	function<ll(int, int, int)> dfs = [&](int idx, int cnt, int p)
	{
		if (cnt == k + 1)
		{
			if (idx == t && !p)
			{
				return 1LL;
			}
			return 0LL;
		}
		if (dp[idx][cnt][p] != -1)
		{
			return dp[idx][cnt][p];
		}
		ll res = 0;
		for (auto &i : graph[idx])
		{
			int nxt = p;
			if (i == x)
			{
				nxt ^= 1;
			}
			res = (res + dfs(i, cnt + 1, nxt)) % MOD;
		}
		return dp[idx][cnt][p] = res;
	};
	cout << dfs(s, 1, 0);
	return 0;
}
