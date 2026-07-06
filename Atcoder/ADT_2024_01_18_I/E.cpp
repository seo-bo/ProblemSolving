#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll d = 0;
	cin >> d;
	ll ans = LLONG_MAX;
	for (ll i = 0; i * i <= d; ++i)
	{
		ll p = sqrt(d - i * i);
		for (ll j = max(0LL, p - 10); j <= p + 10; ++j)
		{
			ans = min(ans, llabs(i * i + j * j - d));
		}
	}
	cout << ans;
	return 0;
}
