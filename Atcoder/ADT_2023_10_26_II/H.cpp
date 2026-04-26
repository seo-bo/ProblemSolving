#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	int A = 0, B = 0, no = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a == x)
		{
			A = i;
		}
		if (a == y)
		{
			B = i;
		}
		if (a > x || a < y)
		{
			no = i;
		}
		ans += max(0, min(A, B) - no);
	}
	cout << ans;
	return 0;
}
