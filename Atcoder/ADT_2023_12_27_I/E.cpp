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
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		p.merge(a, b);
	}
	set<int>s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(p.leader(i));
	}
	cout << s.size();
	return 0;
}
