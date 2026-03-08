#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n + 3);
		ll pivot = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			if (i < 3)
			{
				continue;
			}
			pivot += max(0LL, v[i]);
		}
		cout << max(v[1] + max(0LL, v[2]), 0LL) + pivot << '\n';
	}
	return 0;
}