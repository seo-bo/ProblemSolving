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
	vector<int>cycle(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		char c, d;
		cin >> a >> c >> b >> d;
		if (p.same(a, b))
		{
			cycle[p.leader(a)] = 1;
			continue;
		}
		p.merge(a, b);
	}
	map<int, int>mm;
	for (int i = 1; i <= n; ++i)
	{
		mm[p.leader(i)] |= cycle[i];
	}
	int ans1 = 0, ans2 = 0;
	for (auto& [a, b] : mm)
	{
		ans1 += (b == 1);
		ans2 += (b == 0);
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
