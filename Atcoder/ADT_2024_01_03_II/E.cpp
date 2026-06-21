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
	vector<vector<ll>>v(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		ll zero = 0, pre = -1;
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
			if (j >= 2 && v[i][j] != v[i][j - 1] + 1)
			{
				cout << "No";
				return 0;
			}
			ll a = v[i][j] % 7;
			if (!a)
			{
				a = 7;
			}
			if (zero || pre + 1 != a)
			{
				if (pre != -1)
				{
					cout << "No";
					return 0;
				}
			}
			zero |= (a == 7);
			pre = a;
		}
	}
	for (int j = 1; j <= m; ++j)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (v[i][j] - v[i - 1][j] != 7)
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
