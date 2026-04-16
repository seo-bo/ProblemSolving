#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		ans += (a < m);
	}
	cout << ans;
	return 0;
}
