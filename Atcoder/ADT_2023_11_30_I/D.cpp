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
	for (int i = 0;; ++i)
	{
		if ((1LL << i) > n)
		{
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}
