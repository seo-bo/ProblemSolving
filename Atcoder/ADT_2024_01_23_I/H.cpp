#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ll ans = 0;
	for (int i = 1, ban = 0, a = 0, b = 0; i <= n; ++i)
	{
		if (v[i] == x)
		{
			a = i;
		}
		if (v[i] == y)
		{
			b = i;
		}
		if (y > v[i] || v[i] > x)
		{
			ban = i;
		}
		ans += max(0, min(a, b) - ban);
	}
	cout << ans;
	return 0;
}
