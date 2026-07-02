#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = -(1LL << 31), b = -a;
	cin >> n;
	cout << ((a <= n && n < b) ? "Yes" : "No");
	return 0;
}
