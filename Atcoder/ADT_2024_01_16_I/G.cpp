#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	ll ans = 0;
	while (a != b)
	{
		if (a > b)
		{
			ll p = (a - 1) / b;
			ans += p;
			a -= p * b;
		}
		else
		{
			ll p = (b - 1) / a;
			ans += p;
			b -= p * a;
		}
	}
	cout << ans;
	return 0;
}
