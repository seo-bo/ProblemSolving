#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>dp(87, 2);
	for (int i = 3; i <= 86; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 1] + 2;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		ll t = max(0LL, n - 85 - (n % 2 == 0));
		n -= t, k -= t / 2;
		if (n <= 84 && k > dp[n])
		{
			cout << 0 << '\n';
			continue;
		}
		function<char(ll, ll)> dfs = [&](ll siz, ll target)
			{
				if (target <= 1)
				{
					return '(';
				}
				if (siz <= 2)
				{
					return ')';
				}
				ll len = dp[siz - 2] + 1;
				if (target <= len)
				{
					return dfs(siz - 2, target - 1);
				}
				return dfs(siz - 1, target - len);
			};
		cout << dfs(n, k) << '\n';
	}
	return 0;
}