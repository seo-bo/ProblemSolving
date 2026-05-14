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
	ll ans = 0;
	for (ll i = 1; i * i * i <= n; ++i)
	{
		for (ll j = i; i * j * j <= n; ++j)
		{
			ans += n / (i * j) - j + 1;
		}
	}
	cout << ans;
	return 0;
}
