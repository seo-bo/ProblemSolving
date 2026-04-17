#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll ans = 0, now = 1;
	while (now <= n)
	{
		ll pivot = n / now;
		ll left = now, right = n, res = pivot;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			if (n / mid < pivot)
			{
				right = mid - 1;
			}
			else
			{
				res = mid;
				left = mid + 1;
			}
		}
		res = min(res, n);
		ans += pivot * (res - now + 1);
		now = res + 1;
	}
	cout << ans;
	return 0;
}
