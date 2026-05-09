#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ll left = 1, right = LLONG_MAX / 4, ans = -1;
	auto cal = [&](ll mid)
		{
			ll cnt = k;
			for (ll i = 1; i <= n && cnt >= 0; ++i)
			{
				ll diff = max(0LL, mid - v[i]);
				cnt -= (diff + (i - 1)) / i;
			}
			return (cnt >= 0);
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
