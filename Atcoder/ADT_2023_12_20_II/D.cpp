#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, T = 0;
	cin >> n >> m >> T;
	vector<ll> cost(n), bonus(n + 1);
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		bonus[a] += b;
	}
	for (int i = 1; i <= n - 1; ++i)
	{
		T -= cost[i];
		if (T <= 0)
		{
			cout << "No";
			return 0;
		}
		T += bonus[i + 1];
	}
	cout << "Yes";
	return 0;
}
