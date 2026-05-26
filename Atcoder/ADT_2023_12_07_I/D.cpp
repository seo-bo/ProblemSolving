#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	if (x > 0 && y > 0)
	{
		if (y < x)
		{
			if (z < y)
			{
				cout << abs(z) + abs(z - x);
			}
			else
			{
				cout << -1;
			}
		}
		else
		{
			cout << abs(x);
		}
	}
	else if (x < 0 && y < 0)
	{
		if (x < y)
		{
			if (z > y)
			{
				cout << abs(z) + abs(z - x);
			}
			else
			{
				cout << -1;
			}
		}
		else
		{
			cout << abs(x);
		}
	}
	else
	{
		cout << abs(x);
	}
	return 0;
}
