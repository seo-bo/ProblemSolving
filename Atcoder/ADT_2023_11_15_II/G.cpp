#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, A = 0, B = 0;
	cin >> n >> A >> B;
	auto cal = [&](ll a)
	{
		return a * (a + 1) / 2;
	};
	cout << cal(n) - (cal(n / A) * A + cal(n / B) * B - cal(n / lcm(A, B)) * lcm(A, B));
	return 0;
}
