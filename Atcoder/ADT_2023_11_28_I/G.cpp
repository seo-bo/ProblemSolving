#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> dp(2, -1); // 0 - 노말 / 1 - 배아픔
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		vector<ll> temp = dp;
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			temp[1] = max(temp[1], dp[0] + b);
		}
		else
		{
			temp[0] = max({temp[0], dp[0] + b, dp[1] + b});
		}
		dp = move(temp);
	}
	cout << max(dp[0], dp[1]);
	return 0;
}
