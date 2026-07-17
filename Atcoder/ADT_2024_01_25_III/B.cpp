#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, s = 0, k = 0;
	cin >> n >> s >> k;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		ans += a * b;
	}
	if (ans < s)
	{
		ans += k;
	}
	cout << ans;
	return 0;
}
