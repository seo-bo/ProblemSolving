#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll> dp(2);
	dp[0] = 1;
	for (int i = 2; i <= n; ++i)
	{
		vector<ll> temp(2);
		temp[0] = dp[1];
		temp[1] = (dp[0] * (m - 1) % MOD + dp[1] * (m - 2) % MOD) % MOD;
		dp = move(temp);
	}
	cout << dp[1] * m % MOD;
	return 0;
}
