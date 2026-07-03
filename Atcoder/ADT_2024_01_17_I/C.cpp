#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<vector<char>> v(n, vector<char>(n));
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cin >> j;
		}
	}
	vector<vector<ll>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	auto cal = [&](ll x, ll y)
	{
		ll ans = 0;
		for (ll i = 0; i < 8; ++i)
		{
			ll temp = 0;
			for (ll j = 0; j < n; ++j)
			{
				temp = temp * 10 + (v[x][y] - '0');
				x = (x + dir[i][0] + n) % n;
				y = (y + dir[i][1] + n) % n;
			}
			ans = max(ans, temp);
		}
		return ans;
	};
	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			ans = max(ans, cal(i, j));
		}
	}
	cout << ans;
	return 0;
}
