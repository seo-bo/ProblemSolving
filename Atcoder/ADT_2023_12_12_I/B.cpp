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
	auto cal = [&](ll a)
	{
		return a * a + 2 * a + 3;
	};
	ll a = cal(n + cal(n)), b = n;
	for (int i = 0; i < 2; ++i)
	{
		b = cal(b);
	}
	cout << cal(a + b);
	return 0;
}
