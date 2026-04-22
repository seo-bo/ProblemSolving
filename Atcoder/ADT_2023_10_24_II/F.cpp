#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<pll>v(n + 1);
	v[n] = make_pair(1, 0);
	for (int i = n; i >= 2; --i)
	{
		auto& [a, b] = v[i];
		auto& [c, d] = v[i - 1];
		c += a, b += a * x;
		c += b, d += b * y;
	}
	cout << v[1].second;
	return 0;
}
