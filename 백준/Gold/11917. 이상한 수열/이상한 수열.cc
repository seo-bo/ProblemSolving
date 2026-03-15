#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> m;
	if (m <= n)
	{
		cout << v[m - 1];
		return 0;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int len = v.size(), ans = len + m - n - 1;
	auto it = lower_bound(v.begin(), v.end(), len);
	if (it == v.end() || ans <= *it)
	{
		cout << ans;
		return 0;
	}
	cout << *it;
	return 0;
}