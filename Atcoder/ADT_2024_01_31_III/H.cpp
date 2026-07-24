#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll a = m, b = 0, res = 0;
	for (int i = 2; i <= n; ++i)
	{
		ll p = b;
		b = (a * (m - 1) % MOD + b * (m - 2) % MOD) % MOD;
		a = p;
	}
	cout << b;
	return 0;
}
