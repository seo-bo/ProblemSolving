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
	ll q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		ll sum = 0;
		while (a && b > 1)
		{
			a--;
			ll o = 1 + (b % 2 == 0);
			sum = (sum + o) % 3;
			b = (b + 1) / 2;
		}
		ll ans = sum;
		if (b == 1)
		{
			ans = (ans + a + str[0] - 'A') % 3;
		}
		else
		{
			ans = (ans + str[b - 1] - 'A') % 3;
		}
		cout << char('A' + ans) << '\n';
	}
	return 0;
}
