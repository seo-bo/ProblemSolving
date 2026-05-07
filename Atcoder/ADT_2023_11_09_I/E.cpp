#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, vector<int>> mm;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		mm[a].push_back(b);
	}
	ll ans = 0;
	vector<ll> v;
	for (auto &[a, b] : mm)
	{
		sort(b.rbegin(), b.rend());
		v.push_back(b.front());
		if (b.size() >= 2)
		{
			ans = max(ans, (ll)b[0] + b[1] / 2);
		}
	}
	sort(v.rbegin(), v.rend());
	if (v.size() >= 2)
	{
		ans = max(ans, v[0] + v[1]);
	}
	cout << ans;
	return 0;
}
