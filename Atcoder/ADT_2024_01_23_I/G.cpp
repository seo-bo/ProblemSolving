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
	vector<int> col(n + 1), row(n + 1);
	vector<vector<char>> v(n + 1, vector<char>(n + 1));
	vector<vector<int>> score(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'o')
			{
				row[i]++, col[j]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (v[i][j] == 'x')
			{
				continue;
			}
			ans += (row[i] - 1) * (col[j] - 1);
		}
	}
	cout << ans;
	return 0;
}
