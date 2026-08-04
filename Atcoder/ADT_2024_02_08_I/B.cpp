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
	string ans;
	for (int i = 16; i >= 1; i /= 16)
	{
		int p = n / i;
		if (p >= 10)
		{
			ans += char('A' + p - 10);
		}
		else
		{
			ans += char('0' + p);
		}
		n %= i;
	}
	cout << ans;
	return 0;
}
