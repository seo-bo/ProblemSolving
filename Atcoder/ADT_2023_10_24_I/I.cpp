#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#define INV 499122177

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	while (q--)
	{
		ll sx = 0, ex = 0, sy = 0, ey = 0;
		cin >> sx >> ex >> sy >> ey;
		auto cal = [&](ll a, ll d, ll p)
			{
				return p * ((a * 2 % MOD + (p - 1) * d % MOD) % MOD) % MOD * INV % MOD;
			};
		auto sv = [&](int t) // odd = 0, even = 1
			{
				ll x = sx, nx = ex, y = sy, ny = ey;
				while (x % 2 == t)
				{
					x++;
				}
				while (nx % 2 == t)
				{
					nx--;
				}
				while (y % 2 == t)
				{
					y++;
				}
				while (ny % 2 == t)
				{
					ny--;
				}
				if (x > nx || y > ny)
				{
					return 0LL;
				}
				ll xlen = (nx - x) / 2 + 1, ylen = (ny - y) / 2 + 1;
				return cal(cal(((x - 1) * m % MOD + y) % MOD, 2, ylen) % MOD, ylen * m * 2 % MOD, xlen % MOD);
			};
		cout << (sv(0) + sv(1)) % MOD << '\n';
	}
	return 0;
}
