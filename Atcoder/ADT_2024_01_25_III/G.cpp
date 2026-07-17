#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

ll dp[100001][10];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	vector<tp>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b, c] = v[i];
		cin >> a >> b >> c;
	}
	v.push_back(v.back());
	function<ll(int, int)> dfs = [&](int idx, int now)
		{
			if (idx == n + 1)
			{
				return 0LL;
			}
			if (dp[idx][now] != -1)
			{
				return dp[idx][now];
			}
			auto& [a, b, c] = v[idx];
			ll res = 0, nokori = get<0>(v[idx + 1]) - a;
			for (int i = 0; i <= 4; ++i)
			{
				if (abs(now - i) > nokori)
				{
					continue;
				}
				res = max(res, dfs(idx + 1, i) + c * (b == now));
			}
			return dp[idx][now] = res;
		};
	cout << dfs(0, 0);
	return 0;
}
