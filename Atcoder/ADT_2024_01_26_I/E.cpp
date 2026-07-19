#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

/*
* 초항 a
* 끝항 a + d * (n-1)
* 현재 n
*/


int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, a = 0, d = 0, n = 0;
	cin >> x >> a >> d >> n;
	ll fst = a, lst = a + d * (n - 1);
	if (fst > lst)
	{
		d = -d;
		swap(fst, lst);
	}
	if (x <= fst)
	{
		cout << fst - x;
		return 0;
	}
	if (x >= lst)
	{
		cout << x - lst;
		return 0;
	}
	x = llabs((x - fst) % d);
	cout << min(x, d - x);
	return 0;
}
