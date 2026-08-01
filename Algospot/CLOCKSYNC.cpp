#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>v = { {0, 1, 2},{3, 7, 9, 11},{4, 10, 14, 15}, {0, 4, 5, 6, 7},{6, 7, 8, 10, 12},
		{0, 2, 14, 15},{3, 14, 15},{4, 5, 7, 14, 15},{1, 2, 3, 4, 5},{3, 4, 5, 9, 13} };
	int q = 0;
	cin >> q;
	while (q--)
	{
		vector<int>need(16);
		for (auto& i : need)
		{
			cin >> i;
			i = i % 12 / 3;
		}
		function<int(int)> dfs = [&](int idx)
			{
				if (idx == 10)
				{
					for (auto& i : need)
					{
						if (i)
						{
							return INT_MAX / 8;
						}
					}
					return 0;
				}
				int res = INT_MAX / 8;
				for (int i = 0; i < 4; ++i)
				{
					res = min(res, i + dfs(idx + 1));
					for (auto& j : v[idx])
					{
						need[j] = (need[j] + 1) % 4;
					}
				}
				return res;
			};
		int ans = dfs(0);
		cout << ((ans == INT_MAX / 8) ? -1 : ans) << '\n';
	}
	return 0;
}
