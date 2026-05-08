#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MOD 998244353

ll dp[301][301][301];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pll> pos(4);
	for (int i = 1; i <= 3; ++i)
	{
		auto &[a, b] = pos[i];
		cin >> a >> b;
	}
	set<pll> ban;
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		ban.insert(make_pair(a, b));
	}
	auto cal = [&](int a, int b, int c)
	{
		vector<int> temp = {0, a, b, c};
		ll x = 0, y = 0;
		for (int i = 1; i <= 3; ++i)
		{
			auto [pa, pb] = pos[i];
			x += pa * temp[i];
			y += pb * temp[i];
		}
		return make_pair(x, y);
	};
	function<ll(int, int, int)> dfs = [&](int a, int b, int c)
	{
		if (a + b + c == n)
		{
			return 1LL;
		}
		if (dp[a][b][c] != -1)
		{
			return dp[a][b][c];
		}
		ll res = 0;
		auto [x, y] = cal(a, b, c);
		for (int i = 1; i <= 3; ++i)
		{
			auto &[pa, pb] = pos[i];
			ll nx = x + pa, ny = y + pb;
			ll A = a + (i == 1), B = b + (i == 2), C = c + (i == 3);
			if (ban.find(make_pair(nx, ny)) == ban.end())
			{
				res = (res + dfs(A, B, C)) % MOD;
			}
		}
		return dp[a][b][c] = res;
	};
	cout << dfs(0, 0, 0);
	return 0;
}
