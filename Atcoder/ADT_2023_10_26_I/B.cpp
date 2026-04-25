#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0, q = 0;
	cin >> n >> p >> q;
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		ans = min(ans, min(p, q + a));
	}
	cout << ans;
	return 0;
}
