#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	if (n != m)
	{
		cout << "No";
		return 0;
	}
	dsu p(n + 1);
	vector<int>cycle;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (p.same(a, b))
		{
			cycle.push_back(b);
			continue;
		}
		p.merge(a, b);
	}
	set<int>rt;
	for (int i = 1; i <= n; ++i)
	{
		rt.insert(p.leader(i));
	}
	for (auto& i : cycle)
	{
		rt.erase(p.leader(i));
	}
	cout << ((rt.empty()) ? "Yes" : "No");
	return 0;
}
