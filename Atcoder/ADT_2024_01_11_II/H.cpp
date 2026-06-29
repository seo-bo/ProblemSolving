#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[300001][2][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	function<ll(int, int, int)> dfs = [&](int idx, int now, int fst)
		{
			if (idx == n + 1)
			{
				return (!fst) ? LLONG_MAX / 8 : 0LL;
			}
			if (dp[idx][now][fst] != -1)
			{
				return dp[idx][now][fst];
			}
			ll res = LLONG_MAX / 8, flag = (idx == 1) | (idx == n);
			res = min(res, dfs(idx + 1, 1, fst | flag) + v[idx]);
			if (now)
			{
				res = min(res, dfs(idx + 1, 0, fst));
			}
			return dp[idx][now][fst] = res;
		};
	cout << min(dfs(1, 0, 0), dfs(2, 0, 0));
	return 0;
}
