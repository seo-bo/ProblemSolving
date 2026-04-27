#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n > 0)
	{
		cout << n % MOD;
		return 0;
	}
	ll a = (-n + MOD - 1) / MOD;
	cout << (a * MOD + n);
	return 0;
}
