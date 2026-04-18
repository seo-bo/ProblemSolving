#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	ll ans = LLONG_MAX, prefix = 0, pivot = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		pivot = min(pivot, b);
		prefix += a + b;
		ans = min(ans, prefix + (x - i) * pivot);
	}
	cout << ans;
	return 0;
}
