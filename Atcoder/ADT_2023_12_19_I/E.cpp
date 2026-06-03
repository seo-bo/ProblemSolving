#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
	int ans = 0;
	vector<int> v;
	for (auto &[a, b] : mm)
	{
		sort(b.rbegin(), b.rend());
		if (b.size() != 1)
		{
			ans = max(ans, b[0] + b[1] / 2);
		}
		v.push_back(b[0]);
	}
	sort(v.rbegin(), v.rend());
	if (v.size() > 1)
	{
		ans = max(ans, v[0] + v[1]);
	}
	cout << ans;
	return 0;
}
