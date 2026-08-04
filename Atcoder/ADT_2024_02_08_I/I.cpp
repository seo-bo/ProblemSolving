#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, ll>mm;
	ll prefix = 0, ans = 0, sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		prefix += a;
		ans = (sum + 1) % MOD;
		/*
		* ~~~~ + [a]니까 sum + 1
		*/
		ll temp = (ans - mm[prefix] + MOD) % MOD;
		/*
		* mm[prefix]가 존재한다면 그 사이의 합은 0이니까? 중복 제거해주기
		*/
		mm[prefix] = (mm[prefix] + temp) % MOD;
		sum = (sum + temp) % MOD;
	}
	cout << ans;
	return 0;
}
