#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = (1LL << 62);
	cin >> n;
	while (n < a)
	{
		a >>= 1;
	}
	while (a)
	{
		ll co = (n >= a) ? a : 0;
		cout << ((co) ? 2 : 0);
		n -= co, a >>= 1;
	}
	return 0;
}
