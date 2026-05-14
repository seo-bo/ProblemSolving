#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

/*
a b c - 0
c a b - 2
b c a - 1
a b c - 0
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	int first = 0;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			first = (first - b + n) % n;
		}
		else
		{
			cout << str[(first + b - 1) % n] << '\n';
		}
	}
	return 0;
}
