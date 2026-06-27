#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int dp[301][301][301];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, h = 0;
	cin >> n >> h;
	vector<int>v(n + 1);
	vector<pii>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n - 1; ++i)
	{
		auto& [a, b] = cost[i];
		cin >> a >> b;
	}
	function<int(int, int, int)> dfs = [&](int idx, int now, int nokori)
		{
			if (idx == n)
			{
				return (now >= nokori) ? 0 : INT_MAX / 4;
			}
			if (dp[idx][now][nokori] != -1)
			{
				return dp[idx][now][nokori];
			}
			auto [co, fu] = cost[idx];
			int res = INT_MAX / 4, dist = v[idx + 1] - v[idx];
			if (now - dist >= 0 && nokori + dist <= h) // x
			{
				res = min(res, dfs(idx + 1, now - dist, nokori + dist));
			}
			int nxt = min(h, now + fu);
			if (nxt - dist >= 0 && nokori + dist <= h) // ->
			{
				res = min(res, dfs(idx + 1, nxt - dist, nokori + dist) + co);
			}
			int need = max(0, nokori - fu);
			if (now - dist >= 0 && need + dist <= h) // <-
			{
				res = min(res, dfs(idx + 1, now - dist, need + dist) + co);
			}
			return dp[idx][now][nokori] = res;
		};
	int ans = dfs(0, h, 0);
	cout << ((ans == INT_MAX / 4) ? -1 : ans);
	return 0;
}
