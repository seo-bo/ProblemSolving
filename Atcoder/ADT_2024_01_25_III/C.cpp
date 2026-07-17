#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0, z = 0;
	cin >> n >> x >> y >> z;
	vector<int>ans;
	deque<tp>dq(n);
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b, c] = dq[i];
		cin >> a;
		a = -a;
	}
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b, c] = dq[i];
		cin >> b;
		b = -b;
		c = i + 1;
	}
	sort(dq.begin(), dq.end(), [&](const tp& a, const tp& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<0>(a) < get<0>(b);
		});
	for (int i = 0; i < x; ++i)
	{
		auto& [a, b, c] = dq.front();
		ans.push_back(c);
		dq.pop_front();
	}
	sort(dq.begin(), dq.end(), [&](const tp& a, const tp& b)
		{
			if (get<1>(a) == get<1>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<1>(a) < get<1>(b);
		});
	for (int i = 0; i < y; ++i)
	{
		auto& [a, b, c] = dq.front();
		ans.push_back(c);
		dq.pop_front();
	}
	sort(dq.begin(), dq.end(), [&](const tp& a, const tp& b)
		{
			int A = get<0>(a) + get<1>(a);
			int B = get<0>(b) + get<1>(b);
			if (A == B)
			{
				return get<2>(a) < get<2>(b);
			}
			return A < B;
		});
	for (int i = 0; i < z; ++i)
	{
		auto& [a, b, c] = dq.front();
		ans.push_back(c);
		dq.pop_front();
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
