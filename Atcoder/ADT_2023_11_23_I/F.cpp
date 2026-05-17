#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, a = 0, d = 0, n = 0;
	cin >> x >> a >> d >> n;
	if (d == 0)
	{
		cout << llabs(x - a);
		return 0;
	}
	ll left = min(a, a + (n - 1) * d);
	ll right = max(a, a + (n - 1) * d);
	if (left >= x)
	{
		cout << llabs(x - left);
		return 0;
	}
	if (x >= right)
	{
		cout << llabs(x - right);
		return 0;
	}
	d = llabs(d);
	cout << min((x - left) % d, d - (x - left) % d);
	return 0;
}
