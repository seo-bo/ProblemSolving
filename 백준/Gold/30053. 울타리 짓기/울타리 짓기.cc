#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>A, B;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a < b)
		{
			A.push_back(make_pair(a, b));
		}
		else
		{
			B.push_back(make_pair(a, b));
		}
	}
	vector<int>cost(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> cost[i];
	}
	sort(cost.begin() + 1, cost.end());
	auto cal = [&](vector<pii>& v, int p)
		{
			ll ans = 0;
			vector<int>flag(m + 1);
			vector<vector<ll>>sum(2, vector<ll>(m + 1));
			if (!p)
			{
				flag[1] = 1;
				for (int i = 1, f = 0; i <= m; ++i, f ^= 1)
				{
					flag[i] = f;
					vector<int>temp(2);
					temp[f] = cost[i] - cost[i - 1];
					for (int j = 0; j < 2; ++j)
					{
						sum[j][i] = sum[j][i - 1] + temp[j];
					}
				}
			}
			else
			{
				flag[m] = 1;
				for (int i = m - 1, f = 0; i >= 1; --i, f ^= 1)
				{
					flag[i] = f;
					vector<int>temp(2);
					temp[f] = cost[i + 1] - cost[i];
					for (int j = 0; j < 2; ++j)
					{
						sum[j][i] = sum[j][i + 1] + temp[j];
					}
				}
			}
			for (auto& [a, b] : v)
			{
				int idx = 0, jdx = 0, fp = 0;
				if (!p)
				{
					idx = upper_bound(cost.begin(), cost.end(), a) - cost.begin();
					if (idx > m || cost[idx] >= b)
					{
						continue;
					}
					ans += cost[idx] - a;
					jdx = lower_bound(cost.begin(), cost.end(), b) - cost.begin() - 1;
					if (jdx <= 0 || cost[jdx] < a)
					{
						continue;
					}
					if (++idx >= jdx)
					{
						continue;
					}
					fp = flag[idx] ^ 1;
					ans += sum[fp][jdx] - sum[fp][idx - 1];
				}
				else
				{
					jdx = upper_bound(cost.begin(), cost.end(), b) - cost.begin();
					if (jdx > m || cost[jdx] >= a)
					{
						continue;
					}
					idx = lower_bound(cost.begin(), cost.end(), a) - cost.begin() - 1;
					if (idx <= 0 || cost[idx] <= b)
					{
						continue;
					}
					ans += a - cost[idx];
					if (--idx <= jdx)
					{
						continue;
					}
					fp = flag[idx + 1];
					ans += sum[fp][jdx] - sum[fp][idx + 1];
				}
			}
			return ans;
		};
	cout << cal(A, 0) + cal(B, 1);
	return 0;
}