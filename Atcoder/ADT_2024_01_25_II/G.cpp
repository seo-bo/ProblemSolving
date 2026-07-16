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
	vector<vector<int>>v(2 * n + 1, vector<int>(2 * n + 1));
	for (int i = 1; i <= 2 * n - 1; ++i)
	{
		for (int j = i + 1; j <= 2 * n; ++j)
		{
			cin >> v[i][j];
		}
	}
	ll ans = LLONG_MIN;
	function<void(int, int, ll)> dfs = [&](int idx, int mask, ll sum)
		{
			if (idx == 2 * n + 1)
			{
				ans = max(ans, sum);
				return;
			}
			if (mask & (1 << idx))
			{
				dfs(idx + 1, mask, sum);
				return;
			}
			for (int i = idx + 1; i <= 2 * n; ++i)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				dfs(idx + 1, mask | (1 << i) | (1 << idx), sum ^ v[idx][i]);
			}
		};
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
