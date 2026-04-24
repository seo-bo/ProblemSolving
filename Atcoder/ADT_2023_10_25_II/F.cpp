#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	auto cal = [&](ll a)
		{
			a %= MOD;
			ll inv = 499122177;
			return (a * (a + 1)) % MOD * inv % MOD;
		};
	ll now = 10, ans = 0, c = 1;
	for (; now <= n; now *= 10)
	{
		ans = (ans + cal(now - c)) % MOD;
		c *= 10;
	}
	cout << (ans + cal(n - c + 1)) % MOD;
	return 0;
}
