#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n >= 0)
	{
		ll a = n / MOD;
		cout << n - a * MOD;
		return 0;
	}
	n = -n;
	ll a = (n + MOD - 1) / MOD;
	cout << a * MOD - n;
	return 0;
}
