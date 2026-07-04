#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0;
	cin >> a;
	a %= 100;
	if (a < 10)
	{
		cout << 0;
	}
	cout << a;
	return 0;
}
