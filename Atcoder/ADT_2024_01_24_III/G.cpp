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
	map<int, int>mm;
	map<int, vector<int>>pos;
	int cnt = 1;
	vector<int>ans(n + 1, -1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, idx = 0;
		cin >> a;
		auto it = mm.upper_bound(a);
		if (it == mm.end())
		{
			idx = cnt++;
		}
		else
		{
			idx = it->second;
			mm.erase(it);
		}
		mm[a] = idx, pos[idx].push_back(a);
		if (pos[idx].size() == k)
		{
			mm.erase(a);
			for (auto& j : pos[idx])
			{
				ans[j] = i;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
