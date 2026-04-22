#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (i >= 2 && v[i - 1][j] + 7 != v[i][j])
			{
				cout << "No";
				return 0;
			}
			if (j >= 2 && (v[i][j - 1] + 1 != v[i][j] || v[i][j - 1] % 7 == 0))
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
