#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	{
		auto cal = [&](ld mid) // 0 -> 안고름, 1 -> 고름
		{
			vector<ld> dp(2);
			for (int i = 1; i <= n; ++i)
			{
				vector<ld> temp(2);
				ld co = (ld)v[i] - mid;
				temp[0] = dp[1];
				temp[1] = max(dp[0], dp[1]) + co;
				dp = move(temp);
			}
			return max(dp[0], dp[1]) >= 0;
		};
		ld left = 1, right = INT_MAX, ans = 0;
		for (int i = 1; i <= 100; ++i)
		{
			ld mid = (left + right) / 2;
			if (cal(mid))
			{
				ans = mid;
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		cout << fixed << setprecision(15) << ans << '\n';
	}
	{
		auto cal = [&](ll mid)
		{
			vector<ll> dp(2);
			for (int i = 1; i <= n; ++i)
			{
				vector<ll> temp(2);
				ll co = ((v[i] >= mid) ? 1 : -1);
				temp[0] = dp[1];
				temp[1] = max(dp[0], dp[1]) + co;
				dp = move(temp);
			}
			return max(dp[0], dp[1]) > 0;
		};
		ll left = 1, right = INT_MAX, ans = -1;
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
	}
	return 0;
}
