#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, x = 0, m = 0, sum = 1;
	cin >> a >> x >> m;
	vector<ll> base(1000001, 1);
	for (ll i = 2; i <= 1000000; ++i)
	{
		base[i] = base[i - 1] * a % m;
		sum = (sum + base[i]) % m;
	}
	ll ok = base[1000000] * a % m, ans = 0, pivot = 1;
	while (x >= 1000000)
	{
		x -= 1000000;
		ans = (ans + sum * pivot % m) % m;
		pivot = pivot * ok % m;
	}
	for (int i = 1; x; ++i, --x)
	{
		ans = (ans + base[i] * pivot % m) % m;
	}
	cout << ans;
	return 0;
}
