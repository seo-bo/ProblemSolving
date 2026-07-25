#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	if (x < 0)
	{
		if (y > 0 || y < x)
		{
			cout << -x;
			return 0;
		}
		if (z < y)
		{
			cout << -1;
			return 0;
		}
		cout << abs(z) + abs(z - x);
	}
	else
	{
		if (y < 0 || y > x)
		{
			cout << x;
			return 0;
		}
		if (z > y)
		{
			cout << -1;
			return 0;
		}
		cout << abs(z) + abs(z - x);
	}
	return 0;
}
