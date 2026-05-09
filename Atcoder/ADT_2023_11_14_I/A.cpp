#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	ll ans = 1;
	for (int i = 0; i < (a - b); ++i)
	{
		ans *= 32;
	}
	cout << ans;
	return 0;
}
