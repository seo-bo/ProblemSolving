#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll k = 0, lim = 1e6;
	cin >> k;
	vector<pll>res;
	for (ll i = 2; i * i <= k; ++i)
	{
		if (k % i == 0)
		{
			ll cnt = 0;
			while (k % i == 0)
			{
				k /= i;
				cnt++;
			}
			res.push_back(make_pair(i, cnt));
		}
	}
	if (k > 1)
	{
		res.push_back(make_pair(k, 1));
	}
	ll ans = 0;
	for (auto& [a, b] : res)
	{
		ll left = 0, right = LLONG_MAX / 8, p = 0;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			ll cnt = 0, t = mid;
			while (t)
			{
				t /= a;
				cnt += t;
			}
			if (cnt >= b)
			{
				p = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		ans = max(ans, p);
	}
	cout << ans;
	return 0;
}
