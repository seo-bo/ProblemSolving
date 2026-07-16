#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int k = 0, g = 0, m = 0;
	cin >> k >> g >> m;
	int a = 0, b = 0;
	for (int i = 0; i < k; ++i)
	{
		if (a != g)
		{
			if (!b)
			{
				b = m;
			}
			else
			{
				int p = min(g - a, b);
				a += p, b -= p;
			}
			continue;
		}
		a = 0;
	}
	cout << a << ' ' << b;
	return 0;
}
