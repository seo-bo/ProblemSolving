#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	ll a = 1, b = 0;
	for (int i = n; i >= 2; --i)
	{
		ll na = a;
		b += a * x;
		na += b;
		ll nb = b * y;
		a = na, b = nb;
	}
	cout << b;
	return 0;
}
