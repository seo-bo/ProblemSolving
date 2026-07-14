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
	ll al = max(1 - a, 1 - b), ar = min(n - a, n - b);
	ll bl = max(1 - a, b - n), br = min(n - a, b - 1);
	for (ll x = p; x <= q; ++x)
	{
		for (ll y = r; y <= s; ++y)
		{
			ll ka = x - a, kb = y - b;
			if (ka != kb)
			{
				if (ka != -kb)
				{
					cout << '.';
					continue;
				}
				cout << ((bl <= ka && ka <= br) ? '#' : '.');
				continue;
			}
			cout << ((al <= ka && ka <= ar) ? '#' : '.');
		}
		cout << '\n';
	}
	return 0;
}
