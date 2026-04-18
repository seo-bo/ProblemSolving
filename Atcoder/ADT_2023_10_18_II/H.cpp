#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef pair<pll, pll>pss;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pss>v(n);
	for (auto& [a, b] : v)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		auto& [sx, sy] = a;
		auto& [ex, ey] = b;
		sx = x, sy = y - 1, ex = x - 1, ey = y;
	}
	sort(v.begin(), v.end(), [&](const pss& a, const pss& b)
		{
			auto& [asx, asy] = a.first;
			auto& [aex, aey] = a.second;
			auto& [bsx, bsy] = b.first;
			auto& [bex, bey] = b.second;
			if (aey * bex == aex * bey)
			{
				return asy * bsx < asx * bsy;
			}
			return aey * bex < aex * bey;
		});
	int ans = 0;
	pll now = make_pair(1, 0);
	for (auto& [a, b] : v)
	{
		auto& [sx, sy] = now;
		auto& [ex, ey] = a;
		if (sy * ex <= ey * sx)
		{
			ans++;
			now = b;
		}
	}
	cout << ans;
	return 0;
}
