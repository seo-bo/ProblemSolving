#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<pii> s;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	int ans = 0;
	for (auto &[x1, y1] : s)
	{
		for (auto &[x2, y2] : s)
		{
			if (x1 == x2 || y1 == y2)
			{
				continue;
			}
			pii x3 = make_pair(x1, y2), x4 = make_pair(x2, y1);
			ans += (s.find(x3) != s.end() && s.find(x4) != s.end());
		}
	}
	cout << ans / 4;
	return 0;
}
