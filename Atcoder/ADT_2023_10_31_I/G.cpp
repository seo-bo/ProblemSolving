#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int x = 0, y = 0;
	cin >> x >> y;
	vector<vector<int>>dp(x+1, vector<int>(y+1, INT_MAX));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		vector<vector<int>>temp = dp;
		for (int j = 0; j <= x; ++j)
		{
			for (int k = 0; k <= y; ++k)
			{
				if (dp[j][k] != INT_MAX)
				{
					int na = min(x, j + a), nb = min(y, k + b);
					temp[na][nb] = min(temp[na][nb], dp[j][k] + 1);
				}
			}
		}
		dp = move(temp);
	}
	cout << ((dp[x][y] == INT_MAX) ? -1 : dp[x][y]);
	return 0;
}
