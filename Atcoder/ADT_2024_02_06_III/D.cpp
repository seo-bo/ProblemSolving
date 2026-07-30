#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll p = 1;
	for (ll i = 100; i - 1 <= n; i *= 10, p *= 10)
	{
		n = n - n % p;
	}
	cout << n;
	return 0;
}
