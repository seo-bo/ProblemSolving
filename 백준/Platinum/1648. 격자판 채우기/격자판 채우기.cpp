#include <bits/stdc++.h>
#define MOD 9901
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>dp(1 << (m + 1), vector<int>(n * m, -1));
	function<int(int, int)> dfs = [&](int mask, int pos)
		{
			if (pos == n * m)
			{
				return 1;
			}
			if (dp[mask][pos] != -1)
			{
				return dp[mask][pos];
			}
			int res = 0;
			if (mask & 1)
			{
				res = (res + dfs(mask >> 1, pos + 1)) % MOD;
			}
			else
			{
				if ((pos % m != m - 1) && ((mask & 3) == 0))
				{
					res = (res + dfs(mask >> 2, pos + 2)) % MOD;
				}
				if (pos + m < n * m)
				{
					int temp = mask | (1 << m);
					res = (res + dfs(temp >> 1, pos + 1)) % MOD;
				}
			}
			return dp[mask][pos] = res;
		};
	cout << dfs(0, 0);
	return 0;
}