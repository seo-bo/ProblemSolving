#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, T = 0;
	cin >> n >> m >> T;
	vector<tp>mon(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b, c, d] = mon[i];
		cin >> a >> b >> c >> d;
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	auto cal = [&](ll def)
		{
			int ans = 0;
			vector<int>dp(n + 1, -1);
			{
				auto [a, x, y, c] = mon[1];
				if (max(0LL, -def * y + a))
				{
					return 0;
				}
				dp[1] = ans = c;
			}
			for (int i = 1; i <= T - 1; ++i)
			{
				vector<int>temp = dp;
				for (int j = 1; j <= n; ++j)
				{
					auto [a, x, y, c] = mon[j];
					if (max(0LL, -def * y + a + x * i))
					{
						temp[j] = -1;
						continue;
					}
					for (auto& k : graph[j])
					{
						if (dp[k] == -1)
						{
							continue;
						}
						temp[j] = max(temp[j], dp[k] + c);
						ans = max(ans, temp[j]);
					}
				}
				dp = move(temp);
			}
			return ans;
		};
	int pivot = cal(INT_MAX);
	ll left = 1, right = INT_MAX, ans = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (cal(mid) < pivot)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}