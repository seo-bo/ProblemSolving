#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](int A, int B)
		{
			int a = A / 10, b = A % 10, c = B / 10, d = B % 10;
			int aa = a * 10 + c, bb = b * 10 + d;
			return (aa >= 0 && aa < 24 && bb >= 0 && bb < 60);
		};
	int x = 0, y = 0;
	cin >> x >> y;
	while (!cal(x, y))
	{
		if (++y == 60)
		{
			y = 0;
			if (++x == 24)
			{
				x = 0;
			}
		}
	}
	cout << x << ' ' << y;
	return 0;
}
