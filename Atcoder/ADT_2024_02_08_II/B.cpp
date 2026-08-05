#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, h = 0, x = 0;
	cin >> n >> h >> x;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (h + a >= x)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
