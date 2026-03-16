#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	dp[0][0] = 0;
	for (int i = 1; i <= 2 * n - 1; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = n; j >= 1; --j)
		{
			for (int k = n - 1; k >= 0; --k)
			{
				int nxt = (k + a) % n;
				if (dp[j - 1][k] == -1 || dp[j][nxt] != -1)
				{
					continue;
				}
				dp[j][nxt] = a;
			}
		}
	}
	vector<int>res;
	for (int i = n, x = 0; i >= 1; --i)
	{
		int p = dp[i][x];
		if (p == -1)
		{
			cout << -1;
			return 0;
		}
		res.push_back(p);
		x = (x - p + n) % n;
	}
	for (auto& i : res)
	{
		cout << i << ' ';
	}
	return 0;
}