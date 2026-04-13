#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(3);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a % 3].push_back(a);
	}
	int a = v[0].size(), b = v[1].size(), c = v[2].size();
	if (!a && b && c)
	{
		cout << -1;
		return 0;
	}
	if (a > (n + 1) / 2)
	{
		cout << -1;
		return 0;
	}
	deque<int>dq;
	if (b && c)
	{
		dq.push_back(v[0].back());
		a--, v[0].pop_back();
	}
	for (int i = 1; a + b + c != 0; i ^= 1)
	{
		if (i)
		{
			if (b)
			{
				b--, dq.push_front(v[1].back());
				v[1].pop_back();
			}
			if (c)
			{
				c--, dq.push_back(v[2].back());
				v[2].pop_back();
			}
			continue;
		}
		if (dq.empty())
		{
			cout << v[0].back();
			return 0;
		}
		if (a && dq.front() % 3)
		{
			a--, dq.push_front(v[0].back());
			v[0].pop_back();
		}
		if (a && dq.back() % 3)
		{
			a--, dq.push_back(v[0].back());
			v[0].pop_back();
		}
	}
	for (auto& i : dq)
	{
		cout << i << ' ';
	}
	return 0;
}