#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	int p = 0;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			p = (p + b) % n;
		}
		else
		{
			int idx = (b - 1 - p + n) % n;
			cout << str[idx] << '\n';
		}
	}
	return 0;
}
