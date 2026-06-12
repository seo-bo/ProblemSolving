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
	int a = 0, b = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		char s;
		cin >> s;
		int p = s - '0';
		int na = (p == 0), nb = (p == 1);
		if (p == 0)
		{
			nb += a + b;
		}
		else
		{
			na += b, nb += a;
		}
		ans += nb;
		a = na, b = nb;
	}
	cout << ans;
	return 0;
}
