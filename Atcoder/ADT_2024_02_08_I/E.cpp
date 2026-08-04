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
	vector<vector<int>>v(h + 1, vector<int>(w + 1));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			char a;
			cin >> a;
			v[i][j] = (a == '#');
		}
	}
	int n = min(h, w);
	auto cal = [&](int x, int y, int d)
		{
			for (int i = -1; i <= 1; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					int nx = x + i * d, ny = y + j * d;
					if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && v[nx][ny])
					{
						continue;
					}
					return false;
				}
			}
			return true;
		};
	vector<int>ans(n + 1);
	for (int x = 1; x <= h; ++x)
	{
		for (int y = 1; y <= w; ++y)
		{
			if (!v[x][y])
			{
				continue;
			}
			int res = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (!cal(x, y, i))
				{
					break;
				}
				res = i;
			}
			ans[res]++;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
