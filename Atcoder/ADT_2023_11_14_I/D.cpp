#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> p(n + 1), c(n + 1);
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i] >> c[i];
		for (int j = 0; j < c[i]; ++j)
		{
			int a = 0;
			cin >> a;
			v[i][a] = 1;
		}
	}
	for (int a = 1; a <= n; ++a)
	{
		for (int b = a + 1; b <= n; ++b)
		{
			int i = a, j = b;
			for (int _ = 0; _ < 2; ++_)
			{
				swap(i, j);
				if (p[i] < p[j] || c[i] > c[j])
				{
					continue;
				}
				int flag = 1, cnt = 0;
				for (int k = 1; k <= m; ++k)
				{
					if (v[i][k] && !v[j][k])
					{
						flag = 0;
						break;
					}
					cnt += (!v[i][k] && v[j][k]);
				}
				if (flag)
				{
					if (p[i] > p[j] || cnt)
					{
						cout << "Yes";
						return 0;
					}
				}
			}
		}
	}
	cout << "No";
	return 0;
}
