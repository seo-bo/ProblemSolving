#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ull ans = 0;
	for (ull i = 0, p = 1; i <= 63; ++i, p *= 2)
	{
		ull a = 0;
		cin >> a;
		ans += a * p;
	}
	cout << ans;
	return 0;
}
