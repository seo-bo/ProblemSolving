#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 1;
	cin >> n;
	ll b = n * n;
	while (n--)
	{
		a *= 2;
		if (a > b)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
