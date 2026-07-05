#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	set<pii>s;
	for (int i = 0; i < n; ++i)
	{
		auto [sx, sy] = v[i];
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			auto [ex, ey] = v[j];
			int x = sx - ex, y = sy - ey;
			int g = gcd(x, y);
			x /= g, y /= g;
			s.insert(make_pair(x, y));
		}
	}
	cout << s.size();
	return 0;
}
