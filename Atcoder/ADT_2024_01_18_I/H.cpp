#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	dsu p(n + 2);
	vector<int> cycle(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (p.same(a, b))
		{
			cycle[p.leader(a)]++;
			continue;
		}
		p.merge(a, b);
	}
	vector<int> score(n + 1);
	set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		int t = p.leader(i);
		s.insert(t);
		score[t] += cycle[i];
	}
	ll ans = 1;
	for (auto &i : s)
	{
		if (score[i] != 1)
		{
			cout << 0;
			return 0;
		}
		ans = (ans * 2) % MOD;
	}
	cout << ans;
	return 0;
}
