#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, base = (1LL << 61);
	cin >> x;
	vector<ll> v;
	while (x)
	{
		if (x >= base)
		{
			x -= base;
			v.push_back(base);
		}
		base >>= 1;
	}
	sort(v.begin(), v.end());
	int len = v.size();
	for (int i = 0; i < (1 << len); ++i)
	{
		ll temp = 0;
		for (int j = 0; j < len; ++j)
		{
			if (i & (1 << j))
			{
				temp += v[j];
			}
		}
		cout << temp << '\n';
	}
	return 0;
}
