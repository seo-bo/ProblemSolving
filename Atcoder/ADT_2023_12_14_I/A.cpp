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
	int co = abs(a - b);
	int ax = (a - 1) / 3, bx = (b - 1) / 3;
	cout << ((co == 1 && ax == bx) ? "Yes" : "No");
	return 0;
}
