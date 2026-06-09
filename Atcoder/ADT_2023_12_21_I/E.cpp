#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<int>> v(h + 1, vector<int>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>> dir = {{0, 1}, {1, 0}};
	set<int> s = {v[1][1]};
	int ans = 0;
	function<void(int, int)> dfs = [&](int x, int y)
	{
		if (x == h && y == w)
		{
			ans++;
			return;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
			{
				if (s.find(v[nx][ny]) == s.end())
				{
					s.insert(v[nx][ny]);
					dfs(nx, ny);
					s.erase(v[nx][ny]);
				}
			}
		}
	};
	dfs(1, 1);
	cout << ans;
	return 0;
}
