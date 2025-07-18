#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, ans = 0;
	cin >> n >> k;
	vector<ll>dp(n + 1, 0);
	for (int i = 0; i < k; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		for (int j = n; j >= b; --j)
		{
			dp[j] = max(dp[j], dp[j - b] + a);
			ans = max(ans, dp[j]);
		}
	}
	cout << ans;
	return 0;
}