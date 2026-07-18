#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[500][2][3][1 << 10];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	string str;
	cin >> str;
	int len = str.size();
	function<ll(int, int, int, int)> dfs = [&](int idx, int fit, int three, int mask)
		{
			if (idx == len)
			{
				if (mask == 0)
				{
					return 0LL;
				}
				int f1 = ((mask & (1 << 3)) != 0);
				int f2 = (three == 0);
				int f3 = (__builtin_popcount(mask) == 3);
				int p = f1 + f2 + f3;
				return ((p == 1) ? 1LL : 0LL);
			}
			if (dp[idx][fit][three][mask] != -1)
			{
				return dp[idx][fit][three][mask];
			}
			ll res = 0, p = str[idx] - '0';
			for (int i = 0; i <= 9; ++i)
			{
				if (i == 0 && mask == 0)
				{
					res = (res + dfs(idx + 1, 0, three, 0)) % MOD;
					continue;
				}
				if (i < p)
				{
					res = (res + dfs(idx + 1, 0, (three + i) % 3, mask | (1 << i))) % MOD;
				}
				if (i == p)
				{
					res = (res + dfs(idx + 1, fit, (three + i) % 3, mask | (1 << i))) % MOD;
				}
				if (i > p && !fit)
				{
					res = (res + dfs(idx + 1, 0, (three + i) % 3, mask | (1 << i))) % MOD;
				}
			}
			return dp[idx][fit][three][mask] = res;
		};
	cout << dfs(0, 1, 0, 0);
	return 0;
}
