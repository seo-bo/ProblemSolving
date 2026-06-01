#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, ll> mm;
	ll p = 0, sum = 0, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		p += a;
		ans = (sum + 1) % MOD;
		ll pivot = (ans - mm[p] + MOD) % MOD;
		mm[p] = (mm[p] + pivot) % MOD;
		sum = (sum + pivot) % MOD;
	}
	cout << ans;
	return 0;
}
