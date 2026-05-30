#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, n = 0;
	cin >> a >> b >> n;
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 99; j += 3)
		{
			if(i +j != n)
			{
				continue;
			}
			ans = min(ans, i * a + j / 3 * b);
		}
	}
	cout << ans;
	return 0;
}
