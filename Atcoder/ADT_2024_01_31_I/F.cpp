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
	vector<int>v(m);
	for (auto& i : v)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			i |= (1 << --b);
		}
	}
	int ans = 0;
	function<void(int, int)> dfs = [&](int depth, int mask)
		{
			if (depth == m)
			{
				ans += (mask == (1 << n) - 1);
				return;
			}
			dfs(depth + 1, mask);
			dfs(depth + 1, mask | v[depth]);
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}
