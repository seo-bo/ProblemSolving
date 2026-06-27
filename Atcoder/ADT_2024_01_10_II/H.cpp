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
		ll n = 0, x = 0, k = 0;
		cin >> n >> x >> k;
		auto cal = [&](ll now, ll cnt)
			{
				if (cnt < 0)
				{
					return 0LL;
				}
				ll left = now, right = now, res = 0;
				for (int i = 0; i < cnt; ++i)
				{
					if (left * 2 > n)
					{
						return 0LL;
					}
					left *= 2;
				}
				for (int i = 0; i < cnt; ++i)
				{
					if (right * 2 > LLONG_MAX / 4)
					{
						break;
					}
					right = (right * 2) + 1;
				}
				return min(right, n) - left + 1;
			};
		ll ans = cal(x, k);
		for (int i = 1; i <= k && x > 1; ++i)
		{
			ll pre = x / 2;
			if (i == k)
			{
				ans++;
			}
			ll nxt = ((pre * 2) == x ? x + 1 : x - 1);
			ans += cal(nxt, k - i - 1);
			x = pre;
		}
		cout << ans << '\n';
	}
	return 0;
}
