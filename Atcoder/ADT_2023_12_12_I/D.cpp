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
	vector<vector<int>> v(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a = 0;
			cin >> a;
			v[i][a] = j;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			int flag = 1;
			for (int k = 1; k <= m; ++k)
			{
				int a = v[k][i], b = v[k][j];
				if (a > b)
				{
					swap(a, b);
				}
				if (a + 1 == b)
				{
					flag = 0;
					break;
				}
			}
			ans += flag;
		}
	}
	cout << ans;
	return 0;
}
