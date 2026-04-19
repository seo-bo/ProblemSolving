#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
