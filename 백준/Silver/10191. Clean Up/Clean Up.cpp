#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<string, int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<tp>v(9);
	for (int i = 0; i < 9; ++i)
	{
		auto& [a, b, c, d] = v[i];
		cin >> a >> b >> c;
		d = i + 1;
	}
	for (int i = 0; i < 9; ++i)
	{
		auto& [a, b, c, d] = v[i];
		int e = 0, f = 0;
		cin >> e >> f;
		b += e;
		c += f;
	}
	sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
		{
			auto [a1, a2, a3, a4] = a;
			auto [b1, b2, b3, b4] = b;
			return a2 * b3 > b2 * a3;
		});
	if (get<3>(v[0]) <= 3)
	{
		int pivot = get<3>(v[0]);
		for (auto& [a, b, c, d] : v)
		{
			if (d == pivot)
			{
				d = 4;
			}
			else if (d == 4)
			{
				d = pivot;
			}
		}
		sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
			{
				return get<3>(a) < get<3>(b);
			});
		for (auto& [a, b, c, d] : v)
		{
			cout << a << '\n';
		}
	}
	else if (get<3>(v[0]) >= 5)
	{
		int pivot = get<3>(v[0]);
		for (auto& [a, b, c, d] : v)
		{
			if (d == pivot)
			{
				d = 4;
			}
			else if (d >= 4 && d < pivot)
			{
				d++;
			}
		}
		sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
			{
				return get<3>(a) < get<3>(b);
			});
		for (auto& [a, b, c, d] : v)
		{
			cout << a << '\n';
		}
	}
	else
	{
		sort(v.begin(), v.end(), [&](const tp& a, const tp& b)
			{
				return get<3>(a) < get<3>(b);
			});
		for (auto& [a, b, c, d] : v)
		{
			cout << a << '\n';
		}
	}
	return 0;
}