#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	cout << (((a + 2) % MOD) * ((b + 2) % MOD)) % MOD;
	return 0;
}