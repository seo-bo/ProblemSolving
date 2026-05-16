#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0;
	cin >> a;
	cout << fixed << setprecision(15) << double(sqrtl(a * (12800000 + a)));
	return 0;
}
