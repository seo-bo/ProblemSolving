#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0, k = 0;
	cin >> q >> k;
	vector<ll>dp(k + 1);
	dp[0] = 1;
	while (q--)
	{
		char a;
		int b = 0;
		cin >> a >> b;
		if (a == '+')
		{
			for (int i = k; i >= b; --i)
			{
				dp[i] = (dp[i] + dp[i - b]) % MOD;
			}
		}
		else
		{
			for (int i = b; i <= k; ++i)
			{
				dp[i] = (dp[i] - dp[i - b] + MOD) % MOD;
			}
		}
		cout << dp[k] << '\n';
	}
	return 0;
}
