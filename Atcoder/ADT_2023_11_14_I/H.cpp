#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][6][6][6][6][6];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, k = 0, p = 0;
	cin >> n >> k >> p;
	vector<int> base(6);
	for (int i = 1; i <= k; ++i)
	{
		base[i] = p;
	}
	vector<ll> cost(n + 1);
	vector<vector<int>> up(n + 1, vector<int>(6));
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		for (int j = 1; j <= k; ++j)
		{
			cin >> up[i][j];
		}
	}
	auto cal = [&](int a, int b, int c, int d, int e, vector<int> &add)
	{
		vector<int> temp = {0, a, b, c, d, e};
		for (int i = 1; i <= 5; ++i)
		{
			temp[i] = min(temp[i] + add[i], p);
		}
		return temp;
	};
	function<ll(int, int, int, int, int, int)> dfs = [&](int idx, int a, int b, int c, int d, int e)
	{
		if (idx == n + 1)
		{
			vector<int> now = cal(a, b, c, d, e, up[0]);
			for (int i = 1; i <= 5; ++i)
			{
				if (base[i] > now[i])
				{
					return LLONG_MAX / 8;
				}
			}
			return 0LL;
		}
		if (dp[idx][a][b][c][d][e] != -1)
		{
			return dp[idx][a][b][c][d][e];
		}
		ll res = dfs(idx + 1, a, b, c, d, e);
		vector<int> nxt = cal(a, b, c, d, e, up[idx]);
		res = min(res, dfs(idx + 1, nxt[1], nxt[2], nxt[3], nxt[4], nxt[5]) + cost[idx]);
		return dp[idx][a][b][c][d][e] = res;
	};
	ll ans = dfs(1, 0, 0, 0, 0, 0);
	cout << ((ans == LLONG_MAX / 8) ? -1 : ans);
	return 0;
}
