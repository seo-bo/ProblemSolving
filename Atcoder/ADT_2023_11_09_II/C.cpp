#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll pre = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll a = 0;
		cin >> a;
		cout << a - pre << ' ';
		pre = a;
	}
	return 0;
}
