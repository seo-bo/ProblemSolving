#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll> v(n);
	ll left = 0;
	for (auto &i : v)
	{
		cin >> i;
		left = max(left, i);
	}
	auto cal = [&](ll mid)
	{
		ll cnt = 1, now = mid;
		for (auto &i : v)
		{
			if (now < i)
			{
				cnt++, now = max(0LL, mid - i - 1);
				continue;
			}
			now = max(0LL, now - i - 1);
		}
		return (cnt <= m);
	};
	ll right = LLONG_MAX / 8, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
