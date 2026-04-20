#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, T = 0;
	cin >> n >> m >> T;
	vector<ll>v(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> v[i];
	}
	vector<ll>bonus(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		bonus[a] += b;
	}
	for (int i = 1; i <= n - 1; ++i)
	{
		if (T - v[i] <= 0)
		{
			cout << "No";
			return 0;
		}
		T += bonus[i + 1] - v[i];
	}
	cout << "Yes";
	return 0;
}
