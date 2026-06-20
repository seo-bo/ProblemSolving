#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
	}
	sort(v.begin(), v.end());
	auto cal = [&](ll mid)
		{
			ll cnt = 1, pre = v[0].first;
			for (int i = 1; i < n; ++i)
			{
				auto [ed, st] = v[i];
				if (st >= pre + mid)
				{
					cnt++;
					pre = ed;
				}
			}
			return (cnt >= k);
		};
	ll left = 1, right = LLONG_MAX / 8, ans = -1;
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
