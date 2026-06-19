#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	ll ans = 0;
	for (ll i = len - 1, p = 1; i >= 0; --i, p *= 26)
	{
		ll a = str[i] - 'A' + 1;
		ans += p * a;
	}
	cout << ans;
	return 0;
}
