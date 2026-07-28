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
	vector<vector<int>>v(n, vector<int>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			char a;
			cin >> a;
			j = (a == '#');
		}
	}
	for (int j = 0; j < m; ++j)
	{
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			res += v[i][j];
		}
		cout << res << ' ';
	}
	return 0;
}
