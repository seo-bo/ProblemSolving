#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>pre(n + 1), in(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> pre[i];
		if (i == 1 && pre[i] != 1)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> in[i];
		v[in[i]] = i;
	}
	vector<pii>ans(n + 1);
	function<void(int, int, int, int)> dfs = [&](int ps, int pe, int is, int ie)
		{
			if (ps > pe)
			{
				return;
			}
			int pivot = pre[ps], mid = v[pivot], left = mid - is, right = ie - mid;
			if (mid < is || ie < mid)
			{
				cout << -1;
				exit(0);
			}
			if (left)
			{
				ans[pivot].first = pre[ps + 1];
				dfs(ps + 1, ps + left, is, mid - 1);
			}
			if (right)
			{
				ans[pivot].second = pre[pe - right + 1];
				dfs(pe - right + 1, pe, mid + 1, ie);
			}
		};
	dfs(1, n, 1, n);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = ans[i];
		cout << a << ' ' << b << '\n';
	}
	return 0;
}
