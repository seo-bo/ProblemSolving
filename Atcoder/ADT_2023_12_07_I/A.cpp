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
	int b = a / 5;
	if (a % 5 <= 2)
	{
		cout << b * 5;
		return 0;
	}
	cout << (b + 1) * 5;
	return 0;
}
