#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 0, b = 0, p = 0, q = 0, r = 0, s = 0;
	cin >> n >> a >> b >> p >> q >> r >> s;
	auto cal = [&](ll x, ll y)
	{
		ll a1 = max(1 - a, 1 - b), b1 = min(n - a, n - b);
		{
			ll p1 = x - a, p2 = y - b;
			if (p1 == p2 && a1 <= p1 && p1 <= b1)
			{
				return true;
			}
		}
		ll a2 = max(1 - a, b - n), b2 = min(n - a, b - 1);
		{
			ll p1 = x - a, p2 = y - b;
			if (p1 == -p2 && a2 <= p1 && p1 <= b2)
			{
				return true;
			}
		}
		return false;
	};
	for (ll i = p; i <= q; ++i)
	{
		for (ll j = r; j <= s; ++j)
		{
			cout << (cal(i, j) ? '#' : '.');
		}
		cout << '\n';
	}
	return 0;
}
