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
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		ans[a] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
