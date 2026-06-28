#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	int ans = 0;
	for (int i = m; i <= n; i += p)
	{
		ans++;
	}
	cout << ans;
	return 0;
}
