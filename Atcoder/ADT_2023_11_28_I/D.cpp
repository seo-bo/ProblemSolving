#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	double a = 0, b = 0, d = 0;
	cin >> a >> b >> d;
	double deg = d * acos(-1) / 180 + atan2(b, a);
	double r = sqrt(a * a + b * b);
	double x = r * cos(deg), y = r * sin(deg);
	cout << fixed << setprecision(15) << x << ' ' << y;
	return 0;
}
