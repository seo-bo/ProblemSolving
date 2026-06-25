#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<ll, unordered_map<ll, ll>>dp;
	int n = 0;
	cin >> n;
	vector<tp>v(n + 1);
	ll tot = 0;
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b, c] = v[i];
		cin >> a >> b >> c;
		tot += c;
	}
	function<ll(int, ll)> dfs = [&](int idx, ll score)
		{
			if (idx == n + 1)
			{
				return (score > tot / 2) ? 0LL : LLONG_MAX / 8;
			}
			if (dp.find(idx) != dp.end() && dp[idx].find(score) != dp[idx].end())
			{
				return dp[idx][score];
			}
			ll res = LLONG_MAX / 8;
			auto [ta, ao, co] = v[idx];
			if (ta > ao)
			{
				res = min(res, dfs(idx + 1, score + co));
			}
			else
			{
				ll need = (ta + ao) / 2 + 1;
				res = min({ res, dfs(idx + 1, score), dfs(idx + 1, score + co) + need - ta });
			}
			return dp[idx][score] = res;
		};
	cout << dfs(1, 0);
	return 0;
}
