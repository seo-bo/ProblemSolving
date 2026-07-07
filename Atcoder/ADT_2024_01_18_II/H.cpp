#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;
#define MOD 998244353

ll dp[301][301][301];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int n = 0, m = 0;
	cin >> n >> m;
	ll A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
	cin >> A >> B >> C >> D >> E >> F;
	set<pll>s;
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	function<ll(int, int, int)> dfs = [&](int idx, int a, int b)
		{
			if (idx == n)
			{
				return 1LL;
			}
			if (dp[idx][a][b] != -1)
			{
				return dp[idx][a][b];
			}
			ll res = 0, c = idx - a - b;
			ll x = a * A + b * C + c * E, y = a * B + b * D + c * F;
			ll ax = x + A, ay = y + B;
			if (s.find(make_pair(ax, ay)) == s.end())
			{
				res = (res + dfs(idx + 1, a + 1, b)) % MOD;
			}
			ll bx = x + C, by = y + D;
			if (s.find(make_pair(bx, by)) == s.end())
			{
				res = (res + dfs(idx + 1, a, b + 1)) % MOD;
			}
			ll cx = x + E, cy = y + F;
			if (s.find(make_pair(cx, cy)) == s.end())
			{
				res = (res + dfs(idx + 1, a, b)) % MOD;
			}
			return dp[idx][a][b] = res;
		};
	cout << dfs(0, 0, 0);
	return 0;
}
