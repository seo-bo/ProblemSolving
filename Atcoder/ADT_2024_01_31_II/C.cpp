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
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
		i %= 1000;
	}
	set<int>s;
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		s.insert(a);
	}
	int ans = 0;
	for (auto& i : v)
	{
		if (s.find(i) != s.end())
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
