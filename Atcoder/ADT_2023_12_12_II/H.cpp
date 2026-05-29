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
	vector<ll> cost(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		prefix[i] = prefix[i - 1] + cost[i];
	}
	auto cal = [&](int len)
	{
		ll res = prefix[len / 2] * 2;
		if (len % 2)
		{
			res += cost[(len + 1) / 2];
		}
		return res;
	};
	vector<ll> dp(n + 1, -1);
	function<ll(int)> dfs = [&](int len)
	{
		if (!len)
		{
			return 0LL;
		}
		if (dp[len] != -1)
		{
			return dp[len];
		}
		ll res = 0;
		for (int i = 0; i < len; ++i)
		{
			res = max(res, dfs(len - i - 1) + cal(i));
		}
		return dp[len] = res;
	};
	cout << dfs(n);
	return 0;
}
