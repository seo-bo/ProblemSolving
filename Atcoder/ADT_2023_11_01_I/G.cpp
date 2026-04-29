#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	auto cal = [&](ll mid)
		{
			__int128 pivot = (__int128)mid * m;
			for (auto& i : v)
			{
				pivot -= min(i, mid);
			}
			return (pivot <= 0);
		};
	ll left = 0, right = LLONG_MAX / 8, ans = -1;
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
