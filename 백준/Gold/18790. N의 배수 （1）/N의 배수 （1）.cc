#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[501][501];
int ans[501];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	dp[0][0] = 0;
	for (int i = 1; i <= 2 * n - 1; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = n; j >= 1; --j)
		{
			for (int k = n - 1; k >= 0; --k)
			{
				int nxt = (k + a) % n;
				if (dp[j - 1][k] == -1 || dp[j][nxt] != -1)
				{
					continue;
				}
				dp[j][nxt] = a;
			}
		}
	}
	for (int i = n, x = 0; i >= 1; --i)
	{
		int p = dp[i][x];
		if (p == -1)
		{
			cout << -1;
			return 0;
		}
		ans[n - i + 1] = p;
		x = (x - p + n) % n;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}