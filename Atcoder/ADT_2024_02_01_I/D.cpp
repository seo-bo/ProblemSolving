#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0;
	cin >> x;
	ll ans = x / 10;
	if (x < 0)
	{
		ans = (x - 9) / 10;
	}
	cout << ans;
	return 0;
}
