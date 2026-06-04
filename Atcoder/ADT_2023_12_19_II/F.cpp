#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	dsu p(n + 2);
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (p.same(a, b))
		{
			ans++;
			continue;
		}
		p.merge(a, b);
	}
	cout << ans;
	return 0;
}
