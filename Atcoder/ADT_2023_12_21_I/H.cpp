#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll> dp(m + 1);
	iota(dp.begin(), dp.end(), 0);
	for (int i = 2; i <= n; ++i)
	{
		vector<ll> temp(m + 1);
		for (int j = 1; j <= m; ++j)
		{
			int left = j - k, right = j + k;
			if (left >= 1)
			{
				temp[j] = (temp[j] + dp[left]) % MOD;
			}
			if (right <= m)
			{
				temp[j] = (temp[j] + dp[m] - dp[right - 1] + MOD) % MOD;
			}
			if (!k)
			{
				temp[j] = (temp[j] - dp[j] + dp[j - 1] + MOD) % MOD;
			}
		}
		for (int j = 1; j <= m; ++j)
		{
			temp[j] = (temp[j] + temp[j - 1]) % MOD;
		}
		dp = move(temp);
	}
	cout << dp[m];
	return 0;
}
