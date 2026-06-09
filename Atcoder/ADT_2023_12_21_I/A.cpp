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
	int ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		ans += n;
		n = n % 100 * 10 + n / 100;
	}
	cout << ans;
	return 0;
}
