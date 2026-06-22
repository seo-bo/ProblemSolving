#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	cout << "3.";
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << base[i];
	}
	return 0;
}
