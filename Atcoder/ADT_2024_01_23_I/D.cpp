#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ld a = 0, b = 0, d = 0;
	cin >> a >> b >> d;
	ld p = atan2(b, a), r = sqrt(a * a + b * b), t = d * acos(-1.0) / 180.0;
	ld x = r * cos(p + t), y = r * sin(p + t);
	cout << fixed << setprecision(15) << x << ' ' << y;
	return 0;
}
