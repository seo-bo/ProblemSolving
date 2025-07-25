#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n;
	vector<pld>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	cin >> m;
	while (m--)
	{
		int a = 0;
		cin >> a;
		vector<int>temp(a);
		for (auto& i : temp)
		{
			cin >> i;
		}
		ld ans = 0;
		for (int i = 0; i < a - 1; ++i)
		{
			auto [x1, y1] = v[temp[i]];
			auto [x2, y2] = v[temp[i + 1]];
			ans += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		}
		cout << (ll)round(ans) << '\n';
	}
	return 0;
}