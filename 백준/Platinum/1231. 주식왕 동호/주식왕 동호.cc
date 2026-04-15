#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int c = 0, d = 0, m = 0;
	cin >> c >> d >> m;
	vector<vector<int>>v(c + 2, vector<int>(d + 2));
	for (int i = 1; i <= c; ++i)
	{
		for (int j = 1; j <= d; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<int>dp(500001, -1);
	dp[m] = 0;
	for (int i = 1; i <= d; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			int now = v[j][i], nxt = v[j][i + 1];
			for (int k = 500000; k >= now; --k)
			{
				if (dp[k] == -1)
				{
					continue;
				}
				dp[k - now] = max(dp[k - now], dp[k] + nxt);
			}
		}
		for (int j = 500000; j >= 0; --j)
		{
			if (dp[j] != -1)
			{
				dp[j + dp[j]] = 0;
			}
			if (dp[j])
			{
				dp[j] = -1;
			}
		}
	}
	for (int i = 500000; i >= 0; --i)
	{
		if (!dp[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}