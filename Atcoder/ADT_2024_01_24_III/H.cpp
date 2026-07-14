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
	vector<ld>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ld>dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j >= 1; --j)
		{
			dp[j] = max(dp[j], dp[j - 1] * 0.9 + v[i]);
		}
	}
	ld ans = INT_MIN, p = 0;
	for (int i = 1; i <= n; ++i)
	{
		p = p * 0.9 + 1.0;
		ans = max(ans, dp[i] / p - (ld)1200 / sqrt(i));
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
