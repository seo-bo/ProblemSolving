#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 'a' -> b -> 'c' -> d -> 'a'
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			int cnt = 0;
			for (int k = 1; k <= n; ++k)
			{
				if (k == i || k == j)
				{
					continue;
				}
				cnt += (v[i][k] & v[j][k]);
			}
			ans += cnt * (cnt - 1);
		}
	}
	cout << ans;
	return 0;
}