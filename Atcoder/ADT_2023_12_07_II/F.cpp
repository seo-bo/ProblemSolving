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
	vector<int> ans(n + 2);
	for (int i = 0; i < n; ++i) // (i + p) = (a - 1) -> p = a - i - 1
	{
		int a = 0;
		cin >> a;
		ans[(a - i - 1 + n) % n]++;
		ans[(a - i + n) % n]++;
		ans[(a - i + 1 + n) % n]++;
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		res = max(res, ans[i]);
	}
	cout << res;
	return 0;
}
