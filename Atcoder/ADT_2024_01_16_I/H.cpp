#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ld>dp(101);
	dp[1] = 3.5;
	for (int i = 2; i <= n; ++i)
	{
		for (ld j = 1; j <= 6; ++j)
		{
			dp[i] += max(j, dp[i - 1]);
		}
		dp[i] /= 6;
	}
	cout << fixed << setprecision(15) << dp[n];
	return 0;
}
