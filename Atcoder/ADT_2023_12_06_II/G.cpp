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
	vector<vector<ll>> v(2 * n + 1, vector<ll>(2 * n + 1));
	for (int i = 1; i <= 2 * n; ++i)
	{
		for (int j = i + 1; j <= 2 * n; ++j)
		{
			cin >> v[i][j];
		}
	}
	ll ans = 0;
	function<void(int, int, ll)> dfs = [&](int depth, int mask, ll res)
	{
		if (depth == n)
		{
			ans = max(ans, res);
			return;
		}
		int p = -1;
		for (int i = 1; i <= 2 * n; ++i)
		{
			if (mask & (1 << i))
			{
				continue;
			}
			p = i;
			break;
		}
		for (int i = p + 1; i <= 2 * n; ++i)
		{
			if (mask & (1 << i))
			{
				continue;
			}
			dfs(depth + 1, mask | (1 << p) | (1 << i), res ^ v[p][i]);
		}
	};
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
