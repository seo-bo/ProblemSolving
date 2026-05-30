#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>> dir = {{1, 2}, {2, 1}};
	set<pll> s;
	ll x = 0, y = 0;
	cin >> x >> y;
	for (auto &d : dir)
	{
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				ll nx = x + d[0] * i;
				ll ny = y + d[1] * j;
				s.insert(make_pair(nx, ny));
			}
		}
	}
	cin >> x >> y;
	for (auto &d : dir)
	{
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				ll nx = x + d[0] * i;
				ll ny = y + d[1] * j;
				if (s.find(make_pair(nx, ny)) != s.end())
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}
