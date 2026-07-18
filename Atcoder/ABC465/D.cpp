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
		ll a = 0, b = 0, c = 0, ans = 0;
		cin >> a >> b >> c;
		while (a != b)
		{
			if (a > b)
			{
				a /= c;
			}
			else
			{
				b /= c;
			}
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
