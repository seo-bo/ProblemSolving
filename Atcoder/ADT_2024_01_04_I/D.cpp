#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll k = 0;
	string a, b;
	cin >> k >> a >> b;
	ll A = 0, B = 0, alen = a.size(), blen = b.size();
	for (ll i = alen - 1, t = 1; i >= 0; --i, t *= k)
	{
		A += t * (a[i] - '0');
	}
	for (ll i = blen - 1, t = 1; i >= 0; --i, t *= k)
	{
		B += t * (b[i] - '0');
	}
	cout << A * B;
	return 0;
}
