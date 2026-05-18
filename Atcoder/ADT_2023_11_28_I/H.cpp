#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, y = 0;
	cin >> x >> y;
	vector<ll> v(3);
	for (auto &i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 2; ++i)
	{
		do
		{
			ll x1 = (v[0] + y - 1) / y;
			ll x2 = (v[1] + y - 1) / y;
			ll x3 = (v[2] + y - 1) / y;
			if (x1 + x2 + x3 <= x)
			{
				cout << "Yes";
				return 0;
			}
			if (x1 >= x)
			{
				continue;
			}
			ll nokori = x - x1;
			ll y1 = (v[1] + nokori - 1) / nokori;
			ll y2 = (v[2] + nokori - 1) / nokori;
			if (y1 + y2 <= y)
			{
				cout << "Yes";
				return 0;
			}
		} while (next_permutation(v.begin(), v.end()));
		swap(x, y);
	}
	cout << "No";
	return 0;
}
