#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[101][6][6][6][6][6];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	ll n = 0, k = 0, p = 0;
	cin >> n >> k >> p;
	vector<ll>cost(n + 1), line(6);
	vector<vector<ll>>up(n + 1, vector<ll>(6));
	for (ll i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		for (ll j = 1; j <= k; ++j)
		{
			cin >> up[i][j];
			line[j] = p;
		}
	}
	function<ll(ll, ll, ll, ll, ll, ll)> dfs = [&](ll idx, ll a, ll b, ll c, ll d, ll e)
		{
			if (idx == n + 1)
			{
				ll flag = ((a >= line[1]) & (b >= line[2]) & (c >= line[3]) & (d >= line[4]) & (e >= line[5]));
				return (flag) ? 0LL : LLONG_MAX / 8;
			}
			if (dp[idx][a][b][c][d][e] != -1)
			{
				return dp[idx][a][b][c][d][e];
			}
			ll res = dfs(idx + 1, a, b, c, d, e);
			ll na = min(5LL, a + up[idx][1]);
			ll nb = min(5LL, b + up[idx][2]);
			ll nc = min(5LL, c + up[idx][3]);
			ll nd = min(5LL, d + up[idx][4]);
			ll ne = min(5LL, e + up[idx][5]);
			res = min(res, dfs(idx + 1, na, nb, nc, nd, ne) + cost[idx]);
			return dp[idx][a][b][c][d][e] = res;
		};
	ll ans = dfs(1, 0, 0, 0, 0, 0);
	cout << ((ans == LLONG_MAX / 8) ? -1 : ans);
	return 0;
}
