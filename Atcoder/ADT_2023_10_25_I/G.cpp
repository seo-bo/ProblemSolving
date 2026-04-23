#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>A(n + 1), B(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
	}
	vector<int>dp(3001, 1);
	for (int i = 1; i <= n; ++i)
	{
		vector<int>temp(3001);
		for (int j = 0; j <= 3000; ++j)
		{
			if (A[i] <= j && j <= B[i])
			{
				temp[j] = dp[j];
			}
			if (j)
			{
				temp[j] = (temp[j - 1] + temp[j]) % MOD;
			}
		}
		dp = move(temp);
	}
	cout << dp[3000];
	return 0;
}
