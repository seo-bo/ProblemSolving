#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[101][101][101];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	vector<vector<ll>> per(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		per[a % m].push_back(a);
	}
	for (auto &i : per)
	{
		sort(i.rbegin(), i.rend());
	}
	function<ll(int, int, int)> dfs = [&](int idx, int cnt, int nokori)
	{
		if (idx == m + 1)
		{
			if (cnt == k && nokori == 0)
			{
				return 0LL;
			}
			return LLONG_MIN / 8;
		}
		if (dp[idx][cnt][nokori] != -1)
		{
			return dp[idx][cnt][nokori];
		}
		ll res = dfs(idx + 1, cnt, nokori), sum = 0;
		int len = per[idx].size();
		for (int i = 1; i <= len && cnt + i <= k; ++i)
		{
			sum += per[idx][i - 1];
			res = max(res, dfs(idx + 1, cnt + i, (nokori + sum) % m) + sum);
		}
		return dp[idx][cnt][nokori] = res;
	};
	ll ans = dfs(0, 0, 0);
	cout << ((ans < 0) ? -1 : ans);
	return 0;
}
