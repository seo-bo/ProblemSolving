#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int dp[1001][2][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	vector<vector<int>>dir = { {-1,0},{0,-1},{0,1},{1,0} };
	vector<vector<int>>v(n + 5, vector<int>(m + 5));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	auto cal = [&](int idx, int pre, int now, int nxt)
		{
			for (int i = 1; i <= m; ++i)
			{
				int base = v[idx][i] ^ now, flag = 0;
				for (int j = 0; j < 4; ++j)
				{
					int nx = idx + dir[j][0];
					int ny = i + dir[j][1];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
					{
						int p = v[nx][ny];
						if (j == 0)
						{
							p ^= pre;
						}
						if (j == 1 || j == 2)
						{
							p ^= now;
						}
						if (j == 3)
						{
							p ^= nxt;
						}
						if (base == p)
						{
							flag = 1;
							break;
						}
					}
				}
				if (!flag)
				{
					return 0;
				}
			}
			return 1;
		};
	function<int(int, int, int)> dfs = [&](int idx, int pre, int now)
		{
			if (idx == n + 1)
			{
				return 0;
			}
			if (dp[idx][pre][now] != -1)
			{
				return dp[idx][pre][now];
			}
			int res = INT_MAX / 4;
			if (cal(idx, pre, now, 0))
			{
				res = min(res, dfs(idx + 1, now, 0));
			}
			if (cal(idx, pre, now, 1))
			{
				res = min(res, dfs(idx + 1, now, 1) + 1);
			}
			return dp[idx][pre][now] = res;
		};
	int ans = min(dfs(1, 0, 0), dfs(1, 0, 1) + 1);
	cout << ((ans == INT_MAX / 4) ? -1 : ans);
	return 0;
}
