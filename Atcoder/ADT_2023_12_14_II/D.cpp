#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>> v(101, vector<int>(101));
	for (int _ = 0; _ < n; ++_)
	{
		int sx = 0, ex = 0, sy = 0, ey = 0;
		cin >> sx >> ex >> sy >> ey;
		for (int i = sx; i < ex; ++i)
		{
			for (int j = sy; j < ey; ++j)
			{
				v[i][j] |= 1;
			}
		}
	}
	int ans = 0;
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			ans += j;
		}
	}
	cout << ans;
	return 0;
}
