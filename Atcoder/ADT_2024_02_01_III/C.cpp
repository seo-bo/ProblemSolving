#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0, r = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		if (a <= l)
		{
			cout << l << ' ';
			continue;
		}
		cout << min(max(a, l), r) << ' ';
	}
	return 0;
}
