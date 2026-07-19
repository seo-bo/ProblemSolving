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
	ll ans = 0, prefix = 1;
	for (int i = 0; i < n; ++i)
	{
		char a;
		cin >> a;
		ll p = a - '0', temp = (ans * 10 + p * prefix) % MOD;
		prefix = (prefix + temp) % MOD;
		ans = temp;
	}
	cout << ans;
	return 0;
}
