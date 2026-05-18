#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int a = 0;
			cin >> a;
			ans += a % 2;
		}
		cout << ans << '\n';
	}
	return 0;
}
