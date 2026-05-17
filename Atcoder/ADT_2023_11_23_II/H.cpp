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
	vector<vector<int>> ans(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		int st = 0, cnt = 1;
		cin >> st;
		st += i;
		if (st < 0)
		{
			cnt += (-st + i - 1) / i;
			st += (cnt - 1) * i;
		}
		for (int j = cnt; j <= m && st <= n; ++j)
		{
			ans[j].push_back(st);
			st += i;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		if (ans[i].empty())
		{
			cout << 0 << '\n';
			continue;
		}
		sort(ans[i].begin(), ans[i].end());
		ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end());
		int now = 0;
		for (auto &j : ans[i])
		{
			if (j == now)
			{
				now++;
			}
		}
		cout << now << '\n';
	}
	return 0;
}
