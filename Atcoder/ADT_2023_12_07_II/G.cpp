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
		ll n = 0, d = 0, k = 0;
		cin >> n >> d >> k;
		k--;
		ll a = n / gcd(n, d);
		cout << (k * d + k / a) % n << '\n';
	}
	return 0;
}
