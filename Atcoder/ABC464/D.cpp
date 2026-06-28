#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string str;
		cin >> str;
		vector<ll>x(n + 1), y(n);
		for (int i = 1; i <= n; ++i)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n - 1; ++i)
		{
			cin >> y[i];
		}
		vector<vector<ll>>dp(n + 1, vector<ll>(2, LLONG_MIN));
		function<ll(int, int)> dfs = [&](int idx, int pre)
			{
				if (idx == n + 1)
				{
					return 0LL;
				}
				if (dp[idx][pre] != LLONG_MIN)
				{
					return dp[idx][pre];
				}
				ll res = LLONG_MIN / 8;
				ll co1 = (str[idx - 1] == 'R') ? x[idx] : 0;
				ll co2 = (str[idx - 1] == 'S') ? x[idx] : 0;
				res = max(res, dfs(idx + 1, 0) - co1 + y[idx - 1] * (pre == 1));
				res = max(res, dfs(idx + 1, 1) - co2);
				return dp[idx][pre] = res;
			};
		cout << dfs(1, 0) << '\n';
	}
	return 0;
}
