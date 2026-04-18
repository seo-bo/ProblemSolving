#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	ll a = 0, b = 0;
	int alen = A.size(), blen = B.size();
	for (ll i = alen - 1, temp = 1; i >= 0; --i, temp *= n)
	{
		a += temp * (A[i] - '0');
	}
	for (ll i = blen - 1, temp = 1; i >= 0; --i, temp *= n)
	{
		b += temp * (B[i] - '0');
	}
	cout << a * b;
	return 0;
}
