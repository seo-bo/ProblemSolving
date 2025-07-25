#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	auto sv = [&](int mid)
		{
			vector<vector<int>>dp(len + 1, vector<int>(len + 1, -1));
			function<int(int, int)> dfs = [&](int i, int j)
				{
					if (i == mid || j == len)
					{
						return 0;
					}
					if (dp[i][j] != -1)
					{
						return dp[i][j];
					}
					int res = max(dfs(i + 1, j), dfs(i, j + 1));
					if (str[i] == str[j])
					{
						res = max(res, dfs(i + 1, j + 1) + 1);
					}
					return dp[i][j] = res;
				};
			return min(mid, len - mid) - dfs(0, mid);
		};
	cout << max(sv(len / 2), sv(len / 2 + 1));
	return 0;
}