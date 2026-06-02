#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, x = 0;
	cin >> a >> b >> c >> d >> e >> f >> x;
	c += a, f += d;
	int A = 0, B = 0;
	for (int i = 1, j = 1, p = 1; p <= x; ++i, ++j, ++p)
	{
		if (i > c)
		{
			i = 1;
		}
		if (j > f)
		{
			j = 1;
		}
		if (i <= a)
		{
			A += b;
		}
		if (j <= d)
		{
			B += e;
		}
	}
	cout<< ((A == B) ? "Draw" : (A>B) ? "Takahashi" : "Aoki");
	return 0;
}
