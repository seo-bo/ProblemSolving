#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0;
	cin >> n;
	for (ll i = 1; i <= n;)
	{
		ll left = i, right = n, idx = i, pivot = n / i;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			if (n / mid < pivot)
			{
				right = mid - 1;
			}
			else
			{
				idx = mid;
				left = mid + 1;
			}
		}
		ans += pivot * (idx - i + 1);
		i = idx + 1;
	}
	cout << ans;
	return 0;
}
