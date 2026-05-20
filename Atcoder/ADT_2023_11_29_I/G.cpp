#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> ans(n + 1, -1);
	map<int, vector<int>> mm;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		auto it = mm.lower_bound(a);
		if (it == mm.end())
		{
			if (k == 1)
			{
				ans[a] = i;
			}
			else
			{
				mm[a].push_back(a);
			}
			continue;
		}
		it->second.push_back(a);
		if (it->second.size() == k)
		{
			for (auto &j : it->second)
			{
				ans[j] = i;
			}
			mm.erase(it);
		}
		else if (it->first > a)
		{
			mm[a] = move(it->second);
			mm.erase(it);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
