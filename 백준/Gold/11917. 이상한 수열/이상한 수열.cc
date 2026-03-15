#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n;
	set<int>s;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		s.insert(v[i]);
	}
	cin >> m;
	if (m <= n)
	{
		cout << v[m];
		return 0;
	}
	int len = s.size(), ans = len + m - n - 1;
	auto it = s.lower_bound(len);
	if (it == s.end() || ans <= *it)
	{
		cout << ans;
		return 0;
	}
	cout << *it;
	return 0;
}