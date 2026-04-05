#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<map<pii, int>>v(4);
	auto cal = [&](int a, int b)
		{
			if (a == 0)
			{
				if (b > 0)
				{
					return 3;
				}
				return 1;
			}
			if (b == 0)
			{
				if (a > 0)
				{
					return 0;
				}
				return 2;
			}
			if (a > 0)
			{
				if (b > 0)
				{
					return 0;
				}
				return 1;
			}
			else
			{
				if (b > 0)
				{
					return 3;
				}
				return 2;
			}
		};
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int num = cal(a, b);
		pii p = make_pair(0, 0);
		if (a && b)
		{
			int g = gcd(a, b);
			a /= g, b /= g;
			p = make_pair(a, b);
		}
		v[num][p]++;
	}
	int ans = 0;
	for (auto& i : v)
	{
		for (auto& [a, b] : i)
		{
			ans = max(ans, b);
		}
	}
	cout << ans;
	return 0;
}