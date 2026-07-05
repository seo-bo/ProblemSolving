#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>v(n + 1, vector<int>(3));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i][1];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i][2];
	}
	vector<int>dp(3, 1);
	for (int i = 2; i <= n; ++i)
	{
		vector<int>temp(3);
		for (int j = 1; j <= 2; ++j)
		{
			for (int z = 1; z <= 2; ++z)
			{
				if (dp[z] && abs(v[i - 1][z] - v[i][j]) <= k)
				{
					temp[j] = 1;
				}
			}
		}
		dp = move(temp);
	}
	cout << ((dp[1] | dp[2]) ? "Yes" : "No");
	return 0;
}
