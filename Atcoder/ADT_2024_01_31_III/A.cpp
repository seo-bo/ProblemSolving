#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	--a, --b;
	int ax = a / 3, ay = a % 3;
	int bx = b / 3, by = b % 3;
	if (ax == bx && abs(ay - by) == 1)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
