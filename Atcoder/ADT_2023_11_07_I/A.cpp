#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		int a = n / 100;
		n = n % 100 * 10 + a;
		ans += n;
	}
	cout << ans;
	return 0;
}
