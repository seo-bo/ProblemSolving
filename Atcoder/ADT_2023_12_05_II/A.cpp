#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int a = 21 * 60 + n;
	int h = a / 60, m = a % 60;
	if (h < 10)
	{
		cout << 0;
	}
	cout << h << ":";
	if (m < 10)
	{
		cout << 0;
	}
	cout << m;
	return 0;
}
