#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
			int pre = j - 1, nxt = j + 1;
			temp[j] = (temp[j] + dp[j]) % MOD;
			if (1 <= pre && pre <= 9)
			{
				temp[j] = (temp[j] + dp[pre]) % MOD;
			}
			if (1 <= nxt && nxt <= 9)
			{
				temp[j] = (temp[j] + dp[nxt]) % MOD;
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
