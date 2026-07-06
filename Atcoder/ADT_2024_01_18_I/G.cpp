#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, vector<ll>> pos;
	vector<pll> v(n);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		pos[a].push_back(b);
	}
	for (auto &[a, b] : pos)
	{
		sort(b.begin(), b.end());
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto [ax, ay] = v[i];
		for (int j = i + 1; j < n; ++j)
		{
			auto [bx, by] = v[j];
			if (ax >= bx || ay >= by)
			{
				continue;
			}
			int cx = ax, cy = by;
			int dx = bx, dy = ay;
			int flag = binary_search(pos[cx].begin(), pos[cx].end(), cy) & binary_search(pos[dx].begin(), pos[dx].end(), dy);
			ans += flag;
		}
	}
	cout << ans;
	return 0;
}
