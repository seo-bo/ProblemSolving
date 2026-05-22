#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll s = 0, t = 0, ans = 0;
	cin >> s >> t;
	for (ll a = 0; a <= s; ++a)
	{
		for (ll b = 0; a + b <= s; ++b)
		{
			for (ll c = 0; a + b + c <= s && a * b * c <= t; ++c)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
