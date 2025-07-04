#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>dp(501, -1);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		if (a <= 500 || a >= 20000)
		{
			continue;
		}
		a -= 500;
		vector<ll>temp = dp;
		for (int j = 500; j >= 0; --j)
		{
			if (dp[j] == -1)
			{
				continue;
			}
			int p = (j + a) % 500;
			temp[p] = max(temp[p], dp[j] + a);
		}
		dp = move(temp);
	}
	cout << dp[0];
	return 0;
}