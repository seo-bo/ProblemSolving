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
	int sx = INT_MAX, sy = INT_MAX, ex = INT_MIN, ey = INT_MIN;
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == '.')
			{
				continue;
			}
			sx = min(sx, i), sy = min(sy, j);
			ex = max(ex, i), ey = max(ey, j);
		}
	}
	for (int i = sx; i <= ex; ++i)
	{
		for (int j = sy; j <= ey; ++j)
		{
			if (v[i][j] == '.')
			{
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	}
	return 0;
}
