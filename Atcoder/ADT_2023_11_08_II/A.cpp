#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<pii>s;
	for (int i = 0; i < 3; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	for (auto& [x, _] : s)
	{
		for (auto& [_, y] : s)
		{
			if (s.find(make_pair(x, y)) == s.end())
			{
				cout << x << ' ' << y;
				return 0;
			}
		}
	}
	return 0;
}
