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
	auto cal = [&](ll p)
		{
			ll res = 0;
			for (ll i = 1; i * i <= p; ++i)
			{
				if (p % i)
				{
					continue;
				}
				ll a = p / i;
				res++, res += (a != i);
			}
			return res;
		};
	for (int i = 1; i <= n - 1; ++i)
	{
		ans += cal(i) * cal(n - i);
	}
	cout << ans;
	return 0;
}
