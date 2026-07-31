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
	vector<vector<int>>v(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int pre = 0;
		for (int j = 0; j < n; ++j)
		{
			int a = 0;
			cin >> a;
			v[a][pre] = v[pre][a] = 1;
			pre = a;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			ans += (v[i][j] == 0);
		}
	}
	cout << ans;
	return 0;
}
