#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto [ax, ay] = v[i];
		for (int j = i + 1; j < n; ++j)
		{
			auto [bx, by] = v[j];
			for (int k = j + 1; k < n; ++k)
			{
				auto [cx, cy] = v[k];
				ll px1 = bx - ax, py1 = by - ay, g1 = gcd(px1, py1);
				ll px2 = cx - ax, py2 = cy - ay, g2 = gcd(px2, py2);
				if (px1 / g1 == px2 / g2 && py1 / g1 == py2 / g2)
				{
					continue;
				}
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
