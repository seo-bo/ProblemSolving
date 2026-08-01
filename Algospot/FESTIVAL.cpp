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
		int n = 0, l = 0;
		cin >> n >> l;
		vector<int>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		long double ans = INT_MAX;
		for (int i = 1; i <= n; ++i)
		{
			long double cost = 0;
			for (int j = i; j <= n; ++j)
			{
				cost += v[j];
				int len = j - i + 1;
				if (len < l)
				{
					continue;
				}
				ans = min(ans, cost / len);
			}
		}
		cout << fixed << setprecision(15) << ans << '\n';
	}
	return 0;
}
