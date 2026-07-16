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
	for (ll i = 0, k = 1;; ++i, k <<= 1)
	{
		if (k >= n)
		{
			cout << i - (k > n);
			return 0;
		}
	}
	return 0;
}
