#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	cout << 99 * 3 + 1 << '\n';
	cout << (ll)1e6 << ' ';
	for (int i = 1; i <= 10000; i *= 100)
	{
		for (int j = 1; j <= 99; ++j)
		{
			cout << j * i << ' ';
		}
	}
	return 0;
}
