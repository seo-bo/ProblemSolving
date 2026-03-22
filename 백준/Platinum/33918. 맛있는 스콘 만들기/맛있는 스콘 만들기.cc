#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, c = 0, d = 0;
	cin >> n >> m >> c >> d;
	vector<deque<pii>>dp(c);
	for (int i = 0; i < c; ++i)
	{
		for (int j = i; j <= m; j += c)
		{
			if (!j)
			{
				continue;
			}
			dp[i].push_back(make_pair(j, 0));
		}
	}
	auto psh = [&](deque<pii>& dq, pii pivot)
		{
			auto [a, b] = pivot;
			while (!dq.empty())
			{
				auto [da, db] = dq.back();
				if (db > b)
				{
					break;
				}
				dq.pop_back();
			}
			dq.push_back(pivot);
		};
	for (int i = 0; i < n; ++i)
	{
		vector<deque<pii>>temp(c);
		int a = 0;
		cin >> a;
		for (int j = 0; j < c; ++j)
		{
			deque<pii>left, right;
			while (!dp[j].empty() && dp[j].front().first < j)
			{
				psh(left, dp[j].front());
				dp[j].pop_front();
			}
			while (!dp[j].empty() && dp[j].front().first <= j + d)
			{
				psh(right, dp[j].front());
				dp[j].pop_front();
			}
			for (int k = j; k <= m; k += c)
			{
				if (!k)
				{
					continue;
				}
				while (!left.empty() && left.front().first < k - d)
				{
					left.pop_front();
				}
				while (!right.empty() && right.front().first < k)
				{
					psh(left, right.front());
					right.pop_front();
				}
				if (!dp[j].empty() && dp[j].front().first <= k + d)
				{
					psh(right, dp[j].front());
					dp[j].pop_front();
				}
				int maxi = INT_MIN;
				if (!left.empty())
				{
					auto [pa, pb] = left.front();
					maxi = max(maxi, pb);
				}
				if (!right.empty())
				{
					auto [pa, pb] = right.front();
					maxi = max(maxi, pb);
				}
				temp[j].push_back(make_pair(k, maxi + m - abs(k - a)));
			}
		}
		dp = move(temp);
	}
	int ans = INT_MIN;
	for (auto& i : dp)
	{
		for (auto& [_, a] : i)
		{
			ans = max(ans, a);
		}
	}
	cout << ans;
	return 0;
}