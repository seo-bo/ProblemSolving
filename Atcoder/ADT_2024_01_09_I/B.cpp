#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, x = 0;
	cin >> a >> b >> c >> x;
	if (x <= a)
	{
		cout << 1;
		return 0;
	}
	if (a + 1 <= x && x <= b)
	{
		int p = max(c, b - a);
		cout << fixed << setprecision(15) << (double)c / p;
		return 0;
	}
	cout << 0;
	return 0;
}
