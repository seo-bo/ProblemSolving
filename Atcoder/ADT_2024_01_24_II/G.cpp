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
		ll n = 0, p = 0, q = 0;
		cin >> n;
		for (ll i = 2; i * i <= n / i; ++i)
		{
			if (n % (i * i) == 0)
			{
				p = i;
				q = n / (i * i);
				break;
			}
			if (n % i == 0)
			{
				p = sqrt(n / i);
				q = i;
				break;
			}
		}
		cout << p << ' ' << q << '\n';
	}
	return 0;
}
