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
		cout << n % MOD;
		return 0;
	}
	n = -n;
	ll d = (n + MOD - 1) / MOD;
	cout << d * MOD - n;
	return 0;
}
