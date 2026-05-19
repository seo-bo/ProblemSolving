#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, n = 0;
	cin >> n;
	string str;
	cin >> str;
	for (auto &i : str)
	{
		a += (i == 'o');
		b += (i == 'x');
	}
	cout << ((a && !b) ? "Yes" : "No");
	return 0;
}
