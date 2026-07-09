#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, t = 0;
	cin >> n >> m >> t;
	vector<ll>co(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		cin >> co[i];
	}
	vector<ll>bonus(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		bonus[a] += b;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (t - co[i] <= 0)
		{
			cout << "No";
			return 0;
		}
		t = t - co[i] + bonus[i];
	}
	cout << "Yes";
	return 0;
}
