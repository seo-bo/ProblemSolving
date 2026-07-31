#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<int>dp(x + 1);
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		vector<int>temp = dp;
		int a = 0, b = 0;
		cin >> a >> b;
		for (int j = 1; j <= b; ++j)
		{
			int co = a * j;
			for (int k = x; k >= co; --k)
			{
				if (dp[k - co])
				{
					temp[k] = 1;
				}
			}
		}
		dp = move(temp);
	}
	cout << ((dp[x]) ? "Yes" : "No");
	return 0;
}
