#include <bits/stdc++.h>
using namespace std;
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
	else if (x > b)
	{
		cout << 0;
		return 0;
	}
	cout << fixed << setprecision(15) << (long double)c / (b - a);
	return 0;
}
