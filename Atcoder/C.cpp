#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unsigned long long ans = 0;
	for (unsigned long long i = 0; i <= 63; ++i)
	{
		unsigned long long a = 0;
		cin >> a;
		ans += a * (1ULL << i);
	}
	cout << ans;
	return 0;
}
