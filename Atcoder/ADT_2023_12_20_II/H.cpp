#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[1001][1025][12];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	memset(dp, -1, sizeof(dp));
	function<ll(int, int, int)> dfs = [&](int idx, int mask, int pre)
	{
		if (idx == n)
		{
			return 1LL;
		}
		if (dp[idx][mask][pre] != -1)
		{
			return dp[idx][mask][pre];
		}
		ll res = dfs(idx + 1, mask, pre);
		int now = str[idx] - 'A' + 1;
		if (pre == now || !(mask & (1 << now)))
		{
			res = (res + dfs(idx + 1, mask | (1 << now), now)) % MOD;
		}
		return dp[idx][mask][pre] = res;
	};
	cout << (dfs(0, 0, 0) - 1 + MOD) % MOD;
	return 0;
}
