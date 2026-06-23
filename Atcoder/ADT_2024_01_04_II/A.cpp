#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	for (int i = c; i <= b; i += c)
	{
		if (a <= i)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
