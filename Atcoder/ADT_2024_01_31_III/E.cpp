#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>ans(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		int dist = a - i;
		if (i > a)
		{
			dist += n;
		}
		ans[dist]++, ans[dist + 1]++;
		if (i == a)
		{
			ans[n - 1]++;
		}
		else
		{
			ans[dist - 1]++;
		}
	}
	int res = 0;
	for (int i = 0; i <= n; ++i)
	{
		res = max(res, ans[i]);
	}
	cout << res;
	return 0;
}
