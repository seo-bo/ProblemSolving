#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, A = 0, B = 0, p = 0, q = 0, r = 0, s = 0;
	cin >> n >> A >> B >> p >> q >> r >> s;
	ll ua = max(1 - A, 1 - B), ub = min(n - A, n - B);
	ll da = max(1 - A, B - n), db = min(n - A, B - 1);
	ll h = q - p + 1, w = s - r + 1;
	vector<vector<char>>ans(h + 1, vector<char>(w + 1, '.'));
	for (ll i = p - A, x = p, y = B + p - A; i <= ub && x <= q; ++i, ++x, ++y)
	{
		if (i < ua)
		{
			continue;
		}
		ll nx = x - p + 1, ny = y - r + 1;
		if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
		{
			ans[nx][ny] = '#';
		}
	}
	for (ll i = p - A, x = p, y = B - p + A; i <= db && x <= q; ++i, ++x, --y)
	{
		if (i < da)
		{
			continue;
		}
		ll nx = x - p + 1, ny = y - r + 1;
		if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
		{
			ans[nx][ny] = '#';
		}
	}
	for (ll i = 1; i <= h; ++i)
	{
		for (ll j = 1; j <= w; ++j)
		{
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}
