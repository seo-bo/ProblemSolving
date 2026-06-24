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
		ll n = 0, m = 0;
		cin >> n >> m;
		auto cal = [&](ll f, ll l, ll len)
			{
				return len * (f + l) / 2;
			};
		ll maxi = LLONG_MIN, now = 0, plus = 0;
		for (int i = 0; i < n; ++i)
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			maxi = max(maxi, now + plus + a);
			if (a < 0 && plus > 0)
			{
				ll tlen = min(b, plus / -a), temp = now;
				temp += cal(plus + a, plus + a * tlen, tlen);
				maxi = max(maxi, temp);
			}
			now += cal(plus + a, plus + a * b, b);
			plus += a * b;
			maxi = max(maxi, now);
		}
		cout << maxi << '\n';
	}
	return 0;
}
