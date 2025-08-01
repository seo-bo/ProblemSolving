#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
 
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	ll x = 1, y = 0;
	for (auto& [_, b] : v)
	{
		cin >> b;
	}
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a;
		// (a / b) > (y / x)
		if (a * x > b * y)
		{
			y = a;
			x = b;
		}
	}
	ll ans = 0, temp = 0;
	for (auto& [a, b] : v)
	{
		// (a / b) == (y / x)
		if (a * x == b * y)
		{
			ans = max(ans, ++temp);
		}
		else
		{
			temp = 0;
		}
	}
	ll G = gcd(x, y);
	cout << y / G << ' ' << x / G << '\n';
	cout << ans;
	return 0;
}