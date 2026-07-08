#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> cost(n + 1);
	vector<vector<int>> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			v[i].push_back(b);
		}
	}
	vector<ld> dp(m + 1, INT_MAX);
	dp[m] = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		ld mini = INT_MAX;
		for (int j = 1; j <= n; ++j)
		{
			ld temp = 0, cnt = 0, len = v[j].size();
			for (auto &k : v[j])
			{
				if (!k)
				{
					cnt++;
					continue;
				}
				temp += dp[min(m, i + k)];
			}
			temp = temp / len + cost[j];
			temp /= (ld)1 - cnt / len;
			mini = min(mini, temp);
		}
		dp[i] = mini;
	}
	cout << fixed << setprecision(15) << dp[0];
	return 0;
}
