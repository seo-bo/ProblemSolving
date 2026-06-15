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
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'o')
			{
				v[i] |= (1 << j);
			}
		}
	}
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int depth, int idx, int p)
		{
			if (depth == 2)
			{
				ans += (__builtin_popcount(p) == m);
				return;
			}
			for (int i = idx; i < n; ++i)
			{
				dfs(depth + 1, i + 1, p | v[i]);
			}
		};
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
