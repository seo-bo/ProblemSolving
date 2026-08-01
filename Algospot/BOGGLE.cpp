#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[6][6][11];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		vector<vector<char>>v(6, vector<char>(6));
		for (int i = 1; i <= 5; ++i)
		{
			for (int j = 1; j <= 5; ++j)
			{
				cin >> v[i][j];
			}
		}
		vector<vector<int>>dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
		function<int(int, int, int, string&)> dfs = [&](int x, int y, int idx, string& str)
			{
				if (idx == str.size())
				{
					return 1;
				}
				if (dp[x][y][idx] != -1)
				{
					return dp[x][y][idx];
				}
				int res = 0;
				for (int i = 0; i < 8 && !res; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && v[nx][ny] == str[idx])
					{
						res |= dfs(nx, ny, idx + 1, str);
					}
				}
				return dp[x][y][idx] = res;
			};
		int q = 0;
		cin >> q;
		while (q--)
		{
			memset(dp, -1, sizeof(dp));
			string str;
			cin >> str;
			int flag = 0;
			for (int i = 1; i <= 5 && !flag; ++i)
			{
				for (int j = 1; j <= 5 && !flag; ++j)
				{
					if (v[i][j] == str[0])
					{
						flag |= dfs(i, j, 1, str);
					}
				}
			}
			cout << str << ' ' << ((flag) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
