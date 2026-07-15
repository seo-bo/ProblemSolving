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
	if (a == 1 && b == 10)
	{
		cout << "Yes";
		return 0;
	}
	cout << ((a % 10 + 1 == b) ? "Yes" : "No");
	return 0;
}
