#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ld a = 0, b = 0;
	cin >> a >> b;
	ld p = sqrt(a * a + b * b);
	cout << fixed << setprecision(15) << (ld)a / p << ' ' << (ld)b / p;
	return 0;
}
