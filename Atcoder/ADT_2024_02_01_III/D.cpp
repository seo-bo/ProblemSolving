#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll> v(n);
	ll base = (1 << m) - 1;
	for (auto &i : v)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'o')
			{
				i |= (1LL << j);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ll temp = v[i] | v[j];
			ans += (temp == base);
		}
	}
	cout << ans;
	return 0;
}
