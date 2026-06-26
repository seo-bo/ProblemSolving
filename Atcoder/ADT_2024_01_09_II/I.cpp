#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;
#define MOD 998244353

ll dp[301][301][301];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pii>v(n + 1, make_pair(INT_MIN, INT_MAX));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].second;
	}
	sort(v.begin() + 1, v.end());
	vector<vector<int>>prefix(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			prefix[i][j] = prefix[i - 1][j] + (v[i].second <= j);
		}
	}
	function<ll(int, int, int)> dfs = [&](int idx, int pre, int cnt)
		{
			if (idx == n + 1)
			{
				return (cnt == k) ? 1LL : 0LL;
			}
			if (dp[idx][pre][cnt] != -1)
			{
				return dp[idx][pre][cnt];
			}
			ll res = dfs(idx + 1, pre, cnt);
			auto [px, py] = v[pre];
			auto [nx, ny] = v[idx];
			if (ny < py)
			{
				ll co = prefix[idx][ny] - prefix[pre][ny];
				if (cnt + co <= k)
				{
					res = (res + dfs(idx + 1, idx, cnt + co)) % MOD;
				}
			}
			return dp[idx][pre][cnt] = res;
		};
	cout << dfs(1, 0, 0);
	return 0;
}
