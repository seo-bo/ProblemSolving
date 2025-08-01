#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>prime(200005, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i * i <= 200000; ++i)
	{
		if (prime[i])
		{
			for (ll j = i * i; j <= 200000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	ll n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<vector<ll>>v(3, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[1][i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[2][i];
	}
	vector<ll>dp(n + 1, -1);
	function<ll(int)> dfs = [&](int idx)
		{
			if (idx == n + 1)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = 0;
			res = max(res, dfs(idx + 1) + ((prime[v[1][idx] + v[2][idx]]) ? a : b));
			if (idx <= n - 1)
			{
				ll c1 = ((prime[v[1][idx] + v[1][idx + 1]]) ? a : b);
				ll c2 = ((prime[v[2][idx] + v[2][idx + 1]]) ? a : b);
				res = max(res, dfs(idx + 2) + c1 + c2);
			}
			return dp[idx] = res;
		};
	cout << dfs(1);
	return 0;
}