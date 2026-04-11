#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		prefix[i] = prefix[i - 1] + a;
	}
	vector<ll>dp(n + 1, -1);
	function<ll(int)> dfs = [&](int idx)
		{
			if (!idx)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = dfs(idx - 1);
			return dp[idx] = max(res, prefix[idx] - res);
		};
	cout << dfs(n);
	return 0;
}