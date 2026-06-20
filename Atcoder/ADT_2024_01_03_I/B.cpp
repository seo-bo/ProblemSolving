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
	int p = INT_MAX, ans = -1;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a + h >= x && p > a + h)
		{
			p = a + h;
			ans = i + 1;
		}
	}
	cout << ans;
	return 0;
}
