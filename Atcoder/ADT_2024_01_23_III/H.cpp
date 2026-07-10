#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll A = 0, X = 0, M = 0;
	cin >> A >> X >> M;
	auto power = [&](ll exp)
		{
			ll res = 1, base = A;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % M;
				}
				base = (base * base) % M;
				exp >>= 1;
			}
			return res;
		};
	map<ll, ll>dp;
	dp[0] = 0, dp[1] = 1;
	function<ll(ll)> dfs = [&](ll cnt)
		{
			if (dp.find(cnt) != dp.end())
			{
				return dp[cnt];
			}
			ll left = (cnt + 1) / 2, right = cnt / 2;
			return dp[cnt] = (dfs(left) + power(left) * dfs(right) % M) % M;
		};
	cout << dfs(X) % M;
	return 0;
}
