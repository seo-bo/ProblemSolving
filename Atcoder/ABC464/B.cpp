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
	int sx = 100, sy = 100, ex = -1, ey = -1;
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == '#')
			{
				sx = min(sx, i), sy = min(sy, j);
				ex = max(ex, i), ey = max(ey, j);
			}
		}
	}
	for (int i = sx; i <= ex; ++i)
	{
		for (int j = sy; j <= ey; ++j)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}
