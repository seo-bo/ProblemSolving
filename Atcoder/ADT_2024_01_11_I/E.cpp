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
	vector<int>ans(2 * n + 3);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		ans[2 * i] = ans[2 * i + 1] = ans[a] + 1;
	}
	for (int i = 1; i <= 2 * n + 1; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
