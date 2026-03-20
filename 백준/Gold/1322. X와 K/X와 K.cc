#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, k = 0, ans = 0;
	cin >> x >> k;
	for (ll i = 0; k; ++i)
	{
		if (x & (1LL << i))
		{
			continue;
		}
		if (k & 1)
		{
			ans |= (1LL << i);
		}
		k >>= 1;
	}
	cout << ans;
	return 0;
}