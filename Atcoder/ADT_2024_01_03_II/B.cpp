#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	ll A = 1, B = 1;
	for (int i = 0; i < a; ++i)
	{
		B *= b;
	}
	for (int i = 0; i < b; ++i)
	{
		A *= a;
	}
	cout << A + B;
	return 0;
}
