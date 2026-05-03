#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<ll>dp(3);
	for (auto& i : str)
	{
		ll p = i - 'a', cost = 1;
		dp[p]++;
		for (int j = 0; j < 3; ++j)
		{
			if (j == p)
			{
				continue;
			}
			dp[p] = (dp[p] + dp[j]) % MOD;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans;
	return 0;
}
