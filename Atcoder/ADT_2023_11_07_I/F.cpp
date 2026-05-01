#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>dp(10, 1);
	for (int i = 2; i <= n; ++i)
	{
		vector<ll>temp(10);
		for (int j = 1; j <= 9; ++j)
		{
			for (int k = -1; k <= 1; ++k)
			{
				int pre = j + k;
				if (pre <= 0 || pre >= 10)
				{
					continue;
				}
				temp[j] = (temp[j] + dp[pre]) % MOD;
			}
		}
		dp = move(temp);
	}
	ll ans = 0;
	for (int i = 1; i <= 9; ++i)
	{
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans;
	return 0;
}
