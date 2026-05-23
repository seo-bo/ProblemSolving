#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			char a;
			cin >> a;
			j = a - '0';
		}
	}
	vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x = i, y = j;
			for (int d = 0; d < 8; ++d)
			{
				ll temp = 0;
				for (int k = 0; k < n; ++k)
				{
					temp = temp * 10 + v[x][y];
					x = (x + dir[d][0] + n) % n;
					y = (y + dir[d][1] + n) % n;
				}
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
	return 0;
}
