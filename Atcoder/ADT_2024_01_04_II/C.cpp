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
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int j = 1; j <= m; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
