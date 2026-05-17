#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		auto cal = [&](ll x)
		{
			__int128 left = 1, right = LLONG_MAX;
			while (left <= right)
			{
				__int128 mid = (left + right) / 2;
				if (mid * mid == x)
				{
					return (ll)mid;
				}
				if (mid * mid > x)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			return 0LL;
		};
		int flag = 1;
		for (ll i = 2; i * i * i <= n && flag; ++i)
		{
			ll a = i * i;
			if (n % a == 0)
			{
				cout << i << ' ' << n / a << '\n';
				break;
			}
			if (n % i == 0)
			{
				ll b = n / i, res = cal(b);
				if (res)
				{
					cout << res << ' ' << i << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
