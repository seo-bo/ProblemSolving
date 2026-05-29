#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto sv = [&](vector<vector<int>> &v)
	{
		int n = v.size() - 1, m = v[0].size() - 1;
		int sx = INT_MAX, sy = INT_MAX, ex = 0, ey = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (v[i][j])
				{
					sx = min(sx, i);
					sy = min(sy, j);
					ex = max(ex, i);
					ey = max(ey, j);
				}
			}
		}
		int w = ey - sy + 1;
		vector<vector<int>> res(1, vector<int>(w + 1));
		for (int i = sx; i <= ex; ++i)
		{
			vector<int> temp(1);
			for (int j = sy; j <= ey; ++j)
			{
				temp.push_back(v[i][j]);
			}
			res.push_back(temp);
		}
		return res;
	};
	auto cal = [&]
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>> v(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				char a;
				cin >> a;
				v[i][j] = (a == '#');
			}
		}
		return sv(v);
	};
	vector<vector<int>> A = cal();
	vector<vector<int>> B = cal();
	vector<vector<int>> C = cal();
	int ah = A.size() - 1, aw = A[0].size() - 1;
	int bh = B.size() - 1, bw = B[0].size() - 1;
	vector<int> pos;
	function<bool(int)> dfs = [&](int depth)
	{
		if (depth == 4)
		{
			vector<vector<int>> temp(31, vector<int>(31));
			for (int i = pos[0], ip = 1; ip <= ah; ++i, ++ip)
			{
				for (int j = pos[1], jp = 1; jp <= aw; ++j, ++jp)
				{
					temp[i][j] |= A[ip][jp];
				}
			}
			for (int i = pos[2], ip = 1; ip <= bh; ++i, ++ip)
			{
				for (int j = pos[3], jp = 1; jp <= bw; ++j, ++jp)
				{
					temp[i][j] |= B[ip][jp];
				}
			}
			vector<vector<int>> ans = sv(temp);
			return (ans == C);
		}
		for (int i = 1; i <= 20; ++i)
		{
			pos.push_back(i);
			if (dfs(depth + 1))
			{
				return true;
			}
			pos.pop_back();
		}
		return false;
	};
	cout << ((dfs(0)) ? "Yes" : "No");
	return 0;
}
