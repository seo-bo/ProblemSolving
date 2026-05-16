#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	dsu p(n + 2);
	vector<tp> v(n);
	int st = -1, ed = -1;
	vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	auto cal = [&](ll ax, ll bx)
	{
		return (ax - bx) * (ax - bx);
	};
	for (int i = 0; i < n; ++i)
	{
		auto &[a, b, c] = v[i];
		cin >> a >> b >> c;
		if (cal(a, sx) + cal(b, sy) == c * c)
		{
			st = i;
		}
		if (cal(a, ex) + cal(b, ey) == c * c)
		{
			ed = i;
		}
	}
	if (st == -1 || ed == -1)
	{
		cout << "No";
		return 0;
	}
	auto sv = [&](int a, int b)
	{
		auto [ax, ay, ar] = v[a];
		auto [bx, by, br] = v[b];
		ll d = cal(ax, bx) + cal(ay, by);
		return (cal(ar, br) <= d && d <= cal(ar, -br));
	};
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (sv(i, j) && !p.same(i, j))
			{
				p.merge(i, j);
			}
		}
	}
	cout << ((p.same(st, ed)) ? "Yes" : "No");
	return 0;
}
