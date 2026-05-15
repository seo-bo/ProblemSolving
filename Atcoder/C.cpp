#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0;
	cin >> a;
	if (a >= 0)
	{
		cout << a / 10;
		return 0;
	}
	cout << (a - 9) / 10;
	return 0;
}
