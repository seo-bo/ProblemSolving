#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll k = 0;
	string A, B;
	cin >> k >> A >> B;
	ll a = 0, b = 0, alen = A.size(), blen = B.size();
	for (ll i = alen - 1, p = 1; i >= 0; --i, p *= k)
	{
		ll n = A[i] - '0';
		a += n * p;
	}
	for (ll i = blen - 1, p = 1; i >= 0; --i, p *= k)
	{
		ll n = B[i] - '0';
		b += n * p;
	}
	cout << a * b;
	return 0;
}
