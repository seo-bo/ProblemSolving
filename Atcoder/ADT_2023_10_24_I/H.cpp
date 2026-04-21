#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int>psi;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<psi>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a;
		b = i;
	}
	sort(v.begin() + 1, v.end());
	v.push_back(make_pair("", n + 1));
	vector<int>ans(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		string A, B, C;
		auto [as, an] = v[i - 1];
		auto [bs, bn] = v[i];
		auto [cs, cn] = v[i + 1];
		int len = bs.size();
		for (int j = 0; j < len; ++j)
		{
			if (as.size() > j)
			{
				A += as[j];
			}
			B += bs[j];
			if (cs.size() > j)
			{
				C += cs[j];
			}
			if (A == B)
			{
				ans[an] = max(ans[an], j + 1);
				ans[bn] = max(ans[bn], j + 1);
			}
			if (B == C)
			{
				ans[cn] = max(ans[cn], j + 1);
				ans[bn] = max(ans[bn], j + 1);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
