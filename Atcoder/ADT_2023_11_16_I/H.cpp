#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<ll> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	map<int, map<ll, ll>> dp;
	function<ll(ll, ll)> dfs = [&](int idx, ll nokori)
	{
		if (idx == -1)
		{
			return (nokori) ? LLONG_MAX / 8 : 0LL;
		}
		if (dp.find(idx) != dp.end() && dp[idx].find(nokori) != dp[idx].end())
		{
			return dp[idx][nokori];
		}
		ll p = nokori / v[idx];
		ll res = dfs(idx - 1, nokori % v[idx]) + p;
		res = min(res, dfs(idx - 1, (p + 1) * v[idx] - nokori) + p + 1);
		return dp[idx][nokori] = res;
	};
	cout << dfs(n - 1, x);
	return 0;
}
