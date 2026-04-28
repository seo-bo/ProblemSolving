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
	for (int j = 1; j <= m; ++j)
	{
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			cnt += (v[i][j] == '#');
		}
		cout << cnt << ' ';
	}
	return 0;
}
