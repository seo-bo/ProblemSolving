#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	auto cal = [&](int a, int b, int c, int d)
		{
			for (int i = a; i <= b; ++i)
			{
				for (int j = c; j <= d; ++j)
				{
					if (v[i][j] != v[a + b - i][c + d - j])
					{
						return 0;
					}
				}
			}
			return 1;
		};
	int ans = 0;
	for (int h1 = 1; h1 <= n; ++h1)
	{
		for (int h2 = h1; h2 <= n; ++h2)
		{
			for (int w1 = 1; w1 <= m; ++w1)
			{
				for (int w2 = w1; w2 <= m; ++w2)
				{
					ans += cal(h1, h2, w1, w2);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
