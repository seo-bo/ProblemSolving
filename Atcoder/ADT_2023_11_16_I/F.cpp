#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> h(3), w(3);
	for (auto &i : h)
	{
		cin >> i;
	}
	for (auto &i : w)
	{
		cin >> i;
	}
	vector<vector<int>> v(3, vector<int>(3));
	auto cal = [&]()
	{
		for (int i = 0; i < 3; ++i)
		{
			int col = 0, row = 0;
			int a = 0, b = 0;
			for (int j = 0; j < 3; ++j)
			{
				a += (v[i][j] == 0);
				b += (v[j][i] == 0);
				col += v[i][j], row += v[j][i];
			}
			if (col + a > h[i] || col + 28 * a < h[i] || row + b > w[i] || row + 28 * b < w[i])
			{
				return false;
			}
		}
		return true;
	};
	int ans = 0;
	function<void(int, int)> dfs = [&](int x, int y)
	{
		if (x == 3 && y == 0)
		{
			ans++;
			return;
		}
		for (int i = 1; i <= 28; ++i)
		{
			v[x][y] = i;
			if (cal())
			{
				dfs(x + (y == 2), (y + 1) % 3);
			}
			v[x][y] = 0;
		}
	};
	dfs(0, 0);
	cout << ans;
	return 0;
}
