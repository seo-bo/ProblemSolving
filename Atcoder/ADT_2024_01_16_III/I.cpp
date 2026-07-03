#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353
#define INV 499122177

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	ll ans = 0, pre = 0;
	for (ll i = 0, cnt = 1; i < len; ++i, cnt = (cnt * 2) % MOD)
	{
		ll res = 2 * ans % MOD + pre * 9 % MOD + cnt * (str[i] - '0') * 2 % MOD;
		ll nxt = 10 * pre % MOD + cnt * (str[i] - '0') * 2 % MOD;
		ans = res, pre = nxt;
	}
	cout << ans * INV % MOD;
	return 0;
}
