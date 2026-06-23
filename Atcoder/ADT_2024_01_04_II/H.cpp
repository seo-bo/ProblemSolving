#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[1000001][4];

/*
* 0 - 없음
* 1 - 행만
* 2 - 열만
* 3 - 둘다
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	ll h = 0, w = 0, k = 0;
	cin >> h >> w >> k;
	ll sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	ll flag = (sx == ex) + (sy == ey) * 2;
	function<ll(ll, ll)> dfs = [&](ll idx, ll f)
		{
			if (idx == k)
			{
				return (f == 3) ? 1LL : 0LL;
			}
			if (dp[idx][f] != -1)
			{
				return dp[idx][f];
			}
			ll res = 0;
			if (f == 0)
			{
				res = (res + ((h + w - 4) * dfs(idx + 1, 0) % MOD)) % MOD;
				res = (res + dfs(idx + 1, 1)) % MOD;
				res = (res + dfs(idx + 1, 2)) % MOD;
			}
			if (f == 1)
			{
				res = (res + ((w - 2) * dfs(idx + 1, 1) % MOD)) % MOD;
				res = (res + ((h - 1) * dfs(idx + 1, 0) % MOD)) % MOD;
				res = (res + dfs(idx + 1, 3)) % MOD;
			}
			if (f == 2)
			{
				res = (res + ((h - 2) * dfs(idx + 1, 2) % MOD)) % MOD;
				res = (res + ((w - 1) * dfs(idx + 1, 0) % MOD)) % MOD;
				res = (res + dfs(idx + 1, 3)) % MOD;
			}
			if (f == 3)
			{
				res = (res + ((h - 1) * dfs(idx + 1, 2) % MOD)) % MOD;
				res = (res + ((w - 1) * dfs(idx + 1, 1) % MOD)) % MOD;
			}
			return dp[idx][f] = res;
		};
	cout << dfs(0, flag);
	return 0;
}
