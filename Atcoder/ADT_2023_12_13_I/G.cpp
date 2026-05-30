#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define plus 11111

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<vector<int>> pos(2);
	int ax = 0;
	cin >> ax;
	for (int i = 0, j = 1; i < n - 1; ++i, j ^= 1)
	{
		int a = 0;
		cin >> a;
		pos[j].push_back(a);
	}
	vector<int> target = {x - ax, y};
	for (int i = 0; i < 2; ++i)
	{
		vector<bool> dp(plus * 2 + 15);
		dp[plus] = true;
		for (auto &j : pos[i])
		{
			vector<bool> temp(plus * 2 + 15);
			for (int k = -plus; k <= plus; ++k)
			{
				if (!dp[k + plus])
				{
					continue;
				}
				if (-plus <= k + j && k + j <= plus)
				{
					temp[plus + k + j] = true;
				}
				if (-plus <= k - j && k - j <= plus)
				{
					temp[plus + k - j] = true;
				}
			}
			dp = move(temp);
		}
		if (!dp[plus + target[i]])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
