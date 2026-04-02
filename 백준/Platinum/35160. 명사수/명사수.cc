#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0, c = 0;
	cin >> n >> q >> c;
	deque<pii>plus, zero;
	vector<int>v(n);
	int p = --c;
	for (auto& i : v)
	{
		cin >> i;
	}
	c = min(c, n);
	int f = (c < n);
	auto psh = [&](int pivot, int co, deque<pii>& dq)
		{
			while (!dq.empty() && dq.back().first <= co)
			{
				dq.pop_back();
			}
			dq.push_back(make_pair(co, pivot));
		};
	for (int i = 0; i < c; ++i)
	{
		psh(i, v[i] - i, plus);
	}
	for (int i = c; i < n; ++i)
	{
		psh(i, v[i], zero);
	}
	ll ans = 0;
	for (int i = 0; i < q; ++i)
	{
		int temp = 0;
		if (!plus.empty())
		{
			temp = max(temp, plus.front().first + i + p);
		}
		if (!zero.empty())
		{
			temp = max(temp, zero.front().first);
		}
		ans += temp;
		if (!plus.empty() && plus.front().second == i)
		{
			plus.pop_front();
		}
		if (!zero.empty() && zero.front().second == i + c)
		{
			zero.pop_front();
		}
		int a = i + c, b = i + n;
		if (c)
		{
			psh(a, v[a % n] - a, plus);
		}
		if (f)
		{
			psh(b, v[b % n], zero);
		}
	}
	cout << ans;
	return 0;
}