#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0;
	cin >> n >> p;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		ans += (a < p);
	}
	cout << ans;
	return 0;
}
