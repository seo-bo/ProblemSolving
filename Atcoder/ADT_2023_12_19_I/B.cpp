#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0, p = 0;
	cin >> n >> q >> p;
	ll mini = LLONG_MAX;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		mini = min(mini, a);
	}
	cout << min(q, p + mini);
	return 0;
}
