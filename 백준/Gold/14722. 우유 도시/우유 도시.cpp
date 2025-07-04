#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(3, -1)));
	function<int(int, int, int)> dfs = [&](int x, int y, int now)
		{
			if (x == n || y == n)
			{
				return 0;
			}
			if (dp[x][y][now] != -1)
			{
				return dp[x][y][now];
			}
			int res = 0;
			if (v[x][y] == now)
			{
				res = max({ res, dfs(x + 1,y,(now + 1) % 3) + 1,dfs(x,y + 1,(now + 1) % 3) + 1 });
			}
			res = max({ res, dfs(x + 1,y,now), dfs(x,y + 1,now) });
			return dp[x][y][now] = res;
		};
	cout << dfs(0, 0, 0);
	return 0;
}