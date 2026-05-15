#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<string> v = {"###.?????", "###.?????", "###.?????", "....?????",
						"?????????", "?????....", "?????.###", "?????.###", "?????.###"};
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for (auto &i : grid)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	auto cal = [&](int x, int y)
	{
		vector<string> pivot;
		for (int i = 0; i < 9; ++i)
		{
			string str;
			for (int j = 0; j < 9; ++j)
			{
				str += grid[x + i][y + j];
			}
			pivot.push_back(str);
		}
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (v[i][j] == '?')
				{
					continue;
				}
				if (v[i][j] != pivot[i][j])
				{
					return false;
				}
			}
		}
		return true;
	};
	vector<pii> ans;
	for (int i = 0; i + 9 <= n; ++i)
	{
		for (int j = 0; j + 9 <= m; ++j)
		{
			if (cal(i, j))
			{
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}
	return 0;
}
