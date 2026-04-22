#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v = { 0 };
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		for (auto& j : v)
		{
			j = (j + a) % 360;
		}
		v.push_back(0);
	}
	sort(v.begin(), v.end());
	int len = v.size(), ans = 0;
	for (int i = 0; i < len; ++i)
	{
		ans = max(ans, (v[(i + 1) % len] - v[i] + 360) % 360);
	}
	cout << ans;
	return 0;
}
