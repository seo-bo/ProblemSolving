#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		int res = -1;
		for (int j = 1; j <= 9; ++j)
		{
			if (n % j)
			{
				continue;
			}
			int p = n / j;
			if (i % p == 0)
			{
				res = j;
				break;
			}
		}
		if (res == -1)
		{
			cout << '-';
			continue;
		}
		cout << res;
	}
	return 0;
}
