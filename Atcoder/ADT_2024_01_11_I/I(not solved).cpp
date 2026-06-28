#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[101][1001][1001];
/*
* |pi - qi| = s
*/
ll prefix1[1001][1001]; // (0, s) , (1, s-1) ...
ll prefix2[1001][1001]; // (1, s+1), (2, s+2) ...
ll prefix3[1001][1001]; // (s+1, 1), (s+2, 2) ...

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<int>p(n + 1), q(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> q[i];
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int s = abs(p[i] - q[i]);
		for (int j = 0; j <= d; ++j)
		{
			for (int k = d; k >= 0; --k)
			{
				prefix1[j][k] = dp[i - 1][j][k];
				if (j - 1 >= 0 && k + 1 <= d)
				{
					prefix1[j][k] = (prefix1[j][k] + prefix1[j - 1][k + 1]) % MOD;
				}
			}
		}
		for (int j = 0; j <= d; ++j)
		{
			for (int k = 0; k <= d; ++k)
			{
				prefix2[j][k] = dp[i - 1][j][k];
				if (j - 1 >= 0 && k - 1 >= 0)
				{
					prefix2[j][k] = (prefix2[j][k] + prefix2[j - 1][k - 1]) % MOD;
				}
			}
		}
		for (int j = 0; j <= d; ++j)
		{
			for (int k = 0; k <= d; ++k)
			{
				prefix3[j][k] = dp[i - 1][j][k];
				if (j - 1 >= 0 && k - 1 >= 0)
				{
					prefix3[j][k] = (prefix3[j][k] + prefix3[j - 1][k - 1]) % MOD;
				}
			}
		}
		for (int j = 0; j <= d; ++j)
		{
			for (int k = 0; k <= d; ++k)
			{
			}
		}
	}
	return 0;
}

/*

result : TLE

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll dp[101][1001][1001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, d = 0;
	cin >> n >> d;
	vector<int>p(n + 1), q(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> q[i];
	}
	function<ll(int, int, int)> dfs = [&](int idx, int asum, int bsum)
		{
			if (idx == n + 1)
			{
				return 1LL;
			}
			if (dp[idx][asum][bsum] != -1)
			{
				return dp[idx][asum][bsum];
			}
			ll res = 0;
			for (int i = -2000; i <= 2000; ++i)
			{
				int nxa = asum + abs(p[idx] - i), nxb = bsum + abs(q[idx] - i);
				if (nxa <= d && nxb <= d)
				{
					res = (res + dfs(idx + 1, nxa, nxb)) % MOD;
				}
			}
			return dp[idx][asum][bsum] = res;
		};
	cout << dfs(1, 0, 0);
	return 0;
}
*/
