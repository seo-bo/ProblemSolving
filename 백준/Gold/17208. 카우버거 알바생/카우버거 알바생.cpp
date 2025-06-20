#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
	}
	vector<vector<int>>dp(m + 1, vector<int>(k + 1, -1));
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (int j = m; j >= a; --j)
		{
			for (int z = k; z >= b; --z)
			{
				if (dp[j - a][z - b] == -1)
				{
					continue;
				}
				dp[j][z] = max(dp[j][z], dp[j - a][z - b] + 1);
				ans = max(ans, dp[j][z]);
			}
		}
	}
	cout << ans;
	return 0;
}