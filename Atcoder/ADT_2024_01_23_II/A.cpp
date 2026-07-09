#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](int x)
	{
		return x * x + 2 * x + 3;
	};
	int t = 0;
	cin >> t;
	cout << cal(cal(cal(t) + t) + cal(cal(t)));
	return 0;
}
