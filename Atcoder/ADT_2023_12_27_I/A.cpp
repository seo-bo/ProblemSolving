#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = 0; i <= 255; ++i)
	{
		if ((a ^ i) == b)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
