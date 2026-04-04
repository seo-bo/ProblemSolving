#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<int>>maxi(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i <= n; ++i)
	{
		maxi[i][i] = v[i];
		for (int j = i; j <= n; ++j)
		{
			maxi[i][j] = max(maxi[i][j - 1], v[j]);
		}
	}
	function<int(int, int)> dfs = [&](int left, int right)
		{
			if (right - left <= 1)
			{
				return abs(v[left] - v[right]);
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			int res = INT_MAX / 16;
			for (int i = left; i < right; ++i)
			{
				res = min(res, dfs(left, i) + dfs(i + 1, right) + abs(maxi[left][i] - maxi[i + 1][right]));
			}
			return dp[left][right] = res;
		};
	cout << dfs(1, n);
	return 0;
}