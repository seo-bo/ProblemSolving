#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	if (c >= b || a >= d)
	{
		cout << 0;
		return 0;
	}
	cout << abs(max(a, c) - min(b, d));
	return 0;
}
