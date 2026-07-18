#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0, l = 0, r = 0, a = 0, b = 0;
	cin >> x >> y >> l >> r >> a >> b;
	int ans = 0;
	for (int i = a; i < b; ++i)
	{
		if (l <= i && i < r)
		{
			ans += x;
			continue;
		}
		ans += y;
	}
	cout << ans;
	return 0;
}
