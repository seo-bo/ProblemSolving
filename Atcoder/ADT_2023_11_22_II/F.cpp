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
	vector<int> A(n);
	for (auto &i : A)
	{
		cin >> i;
	}
	sort(A.begin(), A.end());
	int ans = INT_MAX;
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		auto it = lower_bound(A.begin(), A.end(), a);
		if (it != A.begin())
		{
			ans = min(ans, abs(a - *prev(it)));
		}
		if (it != A.end())
		{
			ans = min(ans, abs(a - *it));
			if (next(it) != A.end())
			{
				ans = min(ans, abs(a - *next(it)));
			}
		}
	}
	cout << ans;
	return 0;
}
