#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>dp(n + 1, -1);
	function<int(int)> dfs = [&](int idx)
		{
			if (idx == n + 1)
			{
				return 0;
			}
			if (idx > n)
			{
				return INT_MIN / 6;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			int res = dfs(idx + 1);
			int prefix = 0;
			for (int i = idx, cnt = 1; i <= n && cnt <= m; ++i, ++cnt)
			{
				prefix += v[i];
				res = max(res, dfs(i + cnt + 1) + prefix);
			}
			return dp[idx] = res;
		};
	cout << dfs(1);
	return 0;
}