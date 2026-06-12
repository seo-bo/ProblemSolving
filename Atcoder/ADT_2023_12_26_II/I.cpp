#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair <ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	auto cal = [&](ll mid)
		{
			ll mini = LLONG_MAX, maxi = LLONG_MIN, idx = 0;
			for (auto& [x, y] : v)
			{
				while (idx < n && x - v[idx].first >= mid)
				{
					mini = min(mini, v[idx].second);
					maxi = max(maxi, v[idx].second);
					idx++;
				}
				if (!idx)
				{
					continue;
				}
				if (llabs(mini - y) >= mid || llabs(maxi - y) >= mid)
				{
					return true;
				}
			}
			return false;
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
