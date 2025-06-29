#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		vector<vector<ld>>dp(a + 2, vector<ld>(b + 2, -1.0));
		function<ld(int, int)> dfs = [&](int i, int j)
			{
				if (j <= 0)
				{
					return (ld)1.0;
				}
				if (i <= 0)
				{
					return (ld)0.0;
				}
				if (dp[i][j] >= 0.0)
				{
					return dp[i][j];
				}
				ld res = 0.0;
				res += (ld)0.7 * dfs(i - 1, j); // 1~7
				res += (ld)0.2 * dfs(i - 1, j - 1); // 8~9
				res += (ld)0.1 * dfs(i, j - 1);// 10;
				return dp[i][j] = res;
			};

		cout << fixed << setprecision(3) << dfs(a, b) << '\n';
	}
	return 0;
}