#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, n = 0;
	cin >> h >> w >> n;
	vector<tp>v(n);
	for (int i = 1; i <= n; ++i)
	{
		auto& [x, y, num] = v[i - 1];
		cin >> x >> y;
		num = i;
	}
	sort(v.begin(), v.end());
	int cnt = 0, pre = -1;
	for (auto& [a, b, c] : v)
	{
		if (a != pre)
		{
			pre = a;
			a = ++cnt;
		}
		else
		{
			a = cnt;
		}
	}
	sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
		{
			return get<1>(a) < get<1>(b);
		});
	cnt = 0, pre = -1;
	for (auto& [a, b, c] : v)
	{
		if (b != pre)
		{
			pre = b;
			b = ++cnt;
		}
		else
		{
			b = cnt;
		}
	}
	sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
		{
			return get<2>(a) < get<2>(b);
		});
	for (auto& [a, b, c] : v)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}
