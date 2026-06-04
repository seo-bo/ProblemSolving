#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int sx = INT_MAX, sy = INT_MAX, ex = 1, ey = 1;
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			char a;
			cin >> a;
			if (a == '.')
			{
				continue;
			}
			sx = min(sx, i), sy = min(sy, j);
			ex = max(ex, i), ey = max(ey, j);
		}
	}
	cout << sx << ' ' << ex << '\n' << sy << ' ' << ey;
	return 0;
}
