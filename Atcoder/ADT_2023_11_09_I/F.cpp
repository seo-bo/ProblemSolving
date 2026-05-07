#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll base = (1 << n) - 1;
	vector<ll> v(m);
	for (auto &i : v)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			i |= (1 << (b - 1));
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << m); ++i)
	{
		ll temp = 0;
		for (int j = 0; j < m; ++j)
		{
			if (i & (1 << j))
			{
				temp |= v[j];
			}
		}
		ans += (base == temp);
	}
	cout << ans;
	return 0;
}
