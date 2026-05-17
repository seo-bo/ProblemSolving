#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	ll ans = str[0] - '0', pre = str[0] - '0', cnt = 1;
	for (int i = 1; i < len; ++i)
	{
		ll a = str[i] - '0', old = pre;
		pre = (pre * 10 % MOD + a * cnt * 2 % MOD) % MOD;
		ans = (ans * 2 - old + pre + MOD) % MOD;
		cnt = (cnt * 2) % MOD;
	}
	cout << ans;
	return 0;
}
