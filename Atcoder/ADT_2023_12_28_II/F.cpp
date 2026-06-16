#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 998244353
#define INV 499122177

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ull n = 0, ans = 0;
	cin >> n;
	for (ull i = 1; i <= n; i *= 10)
	{
		ull pivot = min(9 * i, n - i + 1) % MOD;
		pivot = pivot * (pivot + 1) % MOD * INV % MOD;
		ans = (ans + pivot) % MOD;
	}
	cout << ans;
	return 0;
}
