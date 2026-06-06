#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	string ans;
	while (n)
	{
		if (n % 2)
		{
			ans += 'A';
			n--;
			continue;
		}
		ans += 'B';
		n /= 2;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
