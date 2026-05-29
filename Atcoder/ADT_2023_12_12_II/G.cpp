#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<pll> s;
	vector<pll> v(n);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				auto [ax, ay] = v[i];
				auto [bx, by] = v[j];
				ll x = ax - bx, y = ay - by;
				ll g = gcd(x, y);
				s.insert(make_pair(x / g, y / g));
				swap(i, j);
			}
		}
	}
	cout << s.size();
	return 0;
}
