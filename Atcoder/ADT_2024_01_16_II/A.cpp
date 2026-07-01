#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	cin >> a >> b >> c >> d >> e;
	if (++e > b)
	{
		e = 1, d++;
	}
	if (d > a)
	{
		d = 1, c++;
	}
	cout << c << ' ' << d << ' ' << e;
	return 0;
}
