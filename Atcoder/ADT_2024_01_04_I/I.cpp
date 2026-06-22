#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ld a = 0, b = 0;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
	}
	ld ans = (ld)2 * b / sqrt(3);
	if (a < ans)
	{
		ans = sqrtl(a * a * 4 + b * b * 4 - (ld)4 * sqrt(3) * a * b);
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
