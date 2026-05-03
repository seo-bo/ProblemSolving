#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

/*
* 1 -> 1
* 2 -> 3
* 3 -> 6
* 4 -> 10
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	vector<ll>dp(len + 1);
	dp[1] = 1;
	for (ll i = 2, k = 2; i <= len; ++i, ++k)
	{
		dp[i] = (dp[i - 1] + k) % MOD;
	}
	ll ans = 0;
	int temp = 0;
	char pre = 'A';
	for (auto& i : str)
	{
		if (pre == i)
		{
			ans = (ans + dp[temp]) % MOD;
			temp = 1;
			continue;
		}
		temp++;
		pre = i;
	}
	cout << ((ans + dp[temp]) % MOD);
	return 0;
}
