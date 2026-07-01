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
	vector<vector<ll>> v(30, vector<ll>(2));
	for (int i = 0; i < 30; ++i)
	{
		v[i][1] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0, b = 0, nxt = 0;
		cin >> a >> b;
		for (int j = 0; j < 30; ++j)
		{
			ll num = (b >> j) & 1;
			if (a == 1)
			{
				v[j][0] &= num, v[j][1] &= num;
			}
			else if (a == 2)
			{
				v[j][0] |= num, v[j][1] |= num;
			}
			else
			{
				v[j][0] ^= num, v[j][1] ^= num;
			}
			if (v[j][(x >> j) & 1])
			{
				nxt |= (1LL << j);
			}
		}
		cout << nxt << '\n';
		x = nxt;
	}
	return 0;
}
