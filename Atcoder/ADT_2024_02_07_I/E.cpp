#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	vector<pii>dir;
	for (int x = -2; x <= 2; ++x)
	{
		for (int y = -2; y <= 2; ++y)
		{
			if (abs(x * y) != 2)
			{
				continue;
			}
			dir.push_back(make_pair(x, y));
		}
	}
	for (auto& [x, y] : dir)
	{
		ll nx = a + x - c;
		ll ny = b + y - d;
		for (auto& [ax, ay] : dir)
		{
			if (nx == ax && ny == ay)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
