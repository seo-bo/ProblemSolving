#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii> v(4);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
	}
	auto cal = [&](pii a, pii b, pii c)
	{
		ll sx = b.first - a.first;
		ll sy = b.second - a.second;
		ll ex = c.first - b.first;
		ll ey = c.second - b.second;
		return sx * ey - sy * ex > 0;
	};
	for (int i = 0; i < 4; ++i)
	{
		if (!cal(v[i], v[(i + 1) % 4], v[(i + 2) % 4]))
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
