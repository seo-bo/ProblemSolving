#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll base = (1 << m) - 1;
	vector<ll> v(n);
	for (auto &i : v)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'o')
			{
				i |= (1 << j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ans += (base == (v[i] | v[j]));
		}
	}
	cout << ans;
	return 0;
}
