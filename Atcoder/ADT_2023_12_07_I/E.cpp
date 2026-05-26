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
	if (m != n - 1)
	{
		cout << "No";
		return 0;
	}
	vector<int> degree(n + 1);
	dsu p(n + 2);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
		p.merge(a, b);
	}
	int a = 0, b = 0;
	set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(p.leader(i));
		a += (degree[i] == 1);
		b += (degree[i] == 2);
	}
	cout << ((a == 2 && b == n - 2 && s.size() == 1) ? "Yes" : "No");
	return 0;
}
