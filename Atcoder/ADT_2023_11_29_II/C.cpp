#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, k = 0;
	cin >> a >> b >> k;
	for (int i = 1; a < b; ++i)
	{
		a *= k;
		if (a >= b)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
