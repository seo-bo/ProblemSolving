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
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<string>p(m);
	for (auto& i : p)
	{
		cin >> i;
	}
	int base = 0;
	cin >> base;
	map<string, int>mm;
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		mm[p[i]] = a;
	}
	int ans = 0;
	for (auto& i : v)
	{
		if (mm.find(i) == mm.end())
		{
			ans += base;
			continue;
		}
		ans += mm[i];
	}
	cout << ans;
	return 0;
}
