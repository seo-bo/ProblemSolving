#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	while (a || b)
	{
		ll pa = a % 10, pb = b % 10;
		if (pa + pb > 9)
		{
			cout << "Hard";
			return 0;
		}
		a /= 10, b /= 10;
	}
	cout << "Easy";
	return 0;
}
