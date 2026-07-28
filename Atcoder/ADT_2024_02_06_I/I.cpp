#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll dp[18][2 << 18];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	ll n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<ll>A(n), B(n);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	function<ll(int, int)> dfs = [&](int idx, int mask)
		{
			if (idx == -1)
			{
				return 0LL;
			}
			if (dp[idx][mask] != -1)
			{
				return dp[idx][mask];
			}
			ll res = LLONG_MAX / 8;
			int now = 0;
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				ll co = y * (idx - now) + llabs(B[idx] - A[i]) * x;
				res = min(res, dfs(idx - 1, mask | (1 << i)) + co);
				now++;
			}
			return dp[idx][mask] = res;
		};
	cout << dfs(n - 1, 0);
	return 0;
}
