#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = -(1LL << 31), b = (1LL << 31);
	ll n = 0;
	cin >> n;
	if (a <= n && n < b)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
