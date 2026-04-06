#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	set<int>s;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a)
		{
			s.insert(i);
		}
	}
	int now = 0;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a;
		if (a == 3)
		{
			int temp = INT_MAX;
			if (s.empty())
			{
				temp = -1;
			}
			auto a = s.lower_bound(0);
			auto b = s.lower_bound(now);
			if (a != s.end())
			{
				temp = min(temp, n - now + *a);
			}
			if (b != s.end())
			{
				temp = min(temp, *b - now);
			}
			cout << temp << '\n';
			continue;
		}
		cin >> b;
		if (a == 1)
		{
			b--;
			if (s.find(b) == s.end())
			{
				s.insert(b);
			}
			else
			{
				s.erase(b);
			}
		}
		else
		{
			now = (now + b) % n;
		}
	}
	return 0;
}