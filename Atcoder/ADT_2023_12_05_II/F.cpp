#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll> dp(2501);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		vector<ll> temp(2501);
		for (int j = 1; j <= m; ++j)
		{
			for (int p = j; p <= k; ++p)
			{
				temp[p] = (temp[p] + dp[p - j]) % MOD;
			}
		}
		dp = move(temp);
	}
	ll ans = 0;
	for (int i = n; i <= k; ++i)
	{
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans;
	return 0;
}
