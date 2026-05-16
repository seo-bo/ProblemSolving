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
	vector<vector<ll>> cost((1 << n) + 1, vector<ll>(n + 1));
	for (int i = 1; i <= (1 << n); ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> cost[i][j];
		}
	}
	auto cal = [&](int stage, int idx)
	{
		int left = 1, right = -1;
		while (1)
		{
			right = left + (1 << stage) - 1;
			if (left <= idx && idx <= right)
			{
				break;
			}
			left = right + 1;
		}
		int mid = left + (1 << (stage - 1)) - 1;
		if (left <= idx && idx <= mid)
		{
			return make_pair(mid + 1, right);
		}
		return make_pair(left, mid);
	};
	vector<vector<ll>> dp(n + 1, vector<ll>((1 << n) + 1, -1));
	vector<vector<ll>> maxi(n + 1, vector<ll>((1 << n) + 1, -1));
	function<ll(int, int)> dfs = [&](int stage, int idx)
	{
		if (stage == 0)
		{
			return 0LL;
		}
		if (dp[stage][idx] != -1)
		{
			return dp[stage][idx];
		}
		auto [l, r] = cal(stage, idx);
		if (maxi[stage][l] == -1)
		{
			ll res = 0;
			for (int i = l; i <= r; ++i)
			{
				res = max(res, dfs(stage - 1, i) + cost[i][stage - 1]);
			}
			maxi[stage][l] = res;
		}
		return dp[stage][idx] = maxi[stage][l] + dfs(stage - 1, idx);
	};
	ll ans = 0;
	for (int i = 1; i <= (1 << n); ++i)
	{
		ans = max(ans, dfs(n, i) + cost[i][n]);
	}
	cout << ans;
	return 0;
}
