#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 24, b = 2;
	cin >> n;
	for (ll i = 2; i <= n; ++i)
	{
		ll pa = (a * 24 + b * 2) % MOD;
		ll pb = (b * 24 + a * 2) % MOD;
		a = pa;
		b = pb;
	}
	cout << a;
	return 0;
}