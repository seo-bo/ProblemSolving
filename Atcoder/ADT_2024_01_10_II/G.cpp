#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<pii>>siz(3, vector<pii>(4));
	vector<vector<vector<pii>>>v(3, vector<vector<pii>>(4));
	auto cal = [&](int idx)
		{
			int sx = 10, sy = 10, ex = -1, ey = -1;
			vector<pii>temp;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					char a;
					cin >> a;
					if (a == '#')
					{
						temp.push_back(make_pair(i, j));
						sx = min(sx, i), sy = min(sy, j);
						ex = max(ex, i), ey = max(ey, j);
					}
				}
			}
			int r = ex - sx + 1, c = ey - sy + 1;
			siz[idx][0] = siz[idx][2] = make_pair(r, c);
			siz[idx][1] = siz[idx][3] = make_pair(c, r);
			for (auto& [a, b] : temp)
			{
				v[idx][0].push_back(make_pair(a - sx, b - sy));
			}
			for (int i = 1; i <= 3; ++i)
			{
				auto [pr, pc] = siz[idx][i - 1];
				for (auto& [a, b] : v[idx][i - 1])
				{
					v[idx][i].push_back(make_pair(b, pr - 1 - a));
				}
			}
		};
	for (int i = 0; i < 3; ++i)
	{
		cal(i);
	}
	vector<vector<int>>ans(4, vector<int>(4));
	auto sv = [&](int x, int y, int idx, int p)
		{
			for (auto& [a, b] : v[idx][p])
			{
				if (ans[x + a][y + b])
				{
					return false;
				}
			}
			return true;
		};
	function<void(int)> dfs = [&](int idx)
		{
			if (idx == 3)
			{
				int flag = 1;
				for (auto& i : ans)
				{
					for (auto& j : i)
					{
						flag &= j;
					}
				}
				if (flag)
				{
					cout << "Yes";
					exit(0);
				}
				return;
			}
			for (int i = 0; i <= 3; ++i)
			{
				auto [r, c] = siz[idx][i];
				for (int j = 0; j < 16; ++j)
				{
					int x = j / 4, y = j % 4;
					int nx = x + r - 1, ny = y + c - 1;
					if (nx >= 4 || ny >= 4 || !sv(x, y, idx, i))
					{
						continue;
					}
					for (auto& [a, b] : v[idx][i])
					{
						ans[x + a][b + y] = 1;
					}
					dfs(idx + 1);
					for (auto& [a, b] : v[idx][i])
					{
						ans[x + a][b + y] = 0;
					}
				}
			}
		};
	dfs(0);
	cout << "No";
	return 0;
}
