#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>A(n + 1), C(n + 1);
	vector<vector<ll>>prefix(n + 1, vector<ll>(n + 1, LLONG_MAX));
	vector<bool>need(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> C[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		int a = 0;
		cin >> a;
		need[a] = true;
	}
	for (int i = 1; i <= n; ++i)
	{
		prefix[i][0] = C[i];
		for (int j = 1; j <= i - 1; ++j)
		{
			prefix[i][j] = min(prefix[i][j - 1], C[i - j]);
		}
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	function<ll(int, int)> dfs = [&](int idx, int cnt)
		{
			if (idx == n + 1)
			{
				return 0LL;
			}
			if (dp[idx][cnt] != -1)
			{
				return dp[idx][cnt];
			}
			ll res = LLONG_MAX / 8;
			res = min(res, dfs(idx + 1, cnt + 1) + prefix[idx][cnt] + A[idx]);
			if (!need[idx])
			{
				res = min(res, dfs(idx + 1, cnt));
			}
			return dp[idx][cnt] = res;
		};
	cout << dfs(1, 0);
	return 0;
}
