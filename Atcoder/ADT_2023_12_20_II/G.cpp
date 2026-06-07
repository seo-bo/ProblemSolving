#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	ll left = 0, right = a / b;
	auto cal = [&](ll mid)
	{
		return (ld)a / sqrtl(mid + 1) + (ld)b * mid;
	};
	while (right - left >= 100)
	{
		ll pivot = right - left;
		ll p1 = left + pivot / 3, p2 = left + pivot * 2 / 3;
		if (cal(p1) <= cal(p2))
		{
			right = p2;
		}
		else
		{
			left = p1;
		}
	}
	ld ans = a;
	for (ll i = left; i <= right; ++i)
	{
		ans = min(ans, cal(i));
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
