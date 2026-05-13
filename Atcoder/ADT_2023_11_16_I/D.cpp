#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef modint998244353 mint;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<mint> v(6);
	for (auto &i : v)
	{
		ll a = 0;
		cin >> a;
		i = a;
	}
	mint ans = v[0] * v[1] * v[2] - v[3] * v[4] * v[5];
	cout << ans.val();
	return 0;
}
