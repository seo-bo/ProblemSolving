#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[j] = (dp[j] + dp[j - 1]) % MOD;
		}
	}
	cout << dp[n];
	return 0;
}