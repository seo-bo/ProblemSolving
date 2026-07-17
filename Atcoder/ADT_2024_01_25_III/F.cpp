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
	vector<int>a(n);
	for (auto& i : a)
	{
		cin >> i;
	}
	sort(a.begin(), a.end());
	int ans = INT_MAX;
	for (int i = 0; i < m; ++i)
	{
		int b = 0;
		cin >> b;
		auto it = lower_bound(a.begin(), a.end(), b);
		if (it != a.begin())
		{
			ans = min(ans, abs(*prev(it) - b));
		}
		if (it == a.end())
		{
			continue;
		}
		ans = min(ans, abs(*it - b));
		if (next(it) != a.end())
		{
			ans = min(ans, abs(*next(it) - b));
		}
	}
	cout << ans;
	return 0;
}
