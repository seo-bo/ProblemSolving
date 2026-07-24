#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	int sx = INT_MAX, sy = INT_MAX, ex = 0, ey = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char a;
			cin >> a;
			v[i][j] = (a == '#');
			if (v[i][j])
			{
				sx = min(sx, i), ex = max(ex, i);
				sy = min(sy, j), ey = max(ey, j);
			}
		}
	}
	for (int i = sx; i <= ex; ++i)
	{
		for (int j = sy; j <= ey; ++j)
		{
			if (!v[i][j])
			{
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}
