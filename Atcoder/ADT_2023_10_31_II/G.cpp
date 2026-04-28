#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // ABC -> 012
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0, pivot = 0;
		cin >> a >> b;
		b--;
		while (a && b)
		{
			pivot = (pivot + 1 + b % 2) % 3;
			b /= 2, a--;
		}
		pivot = (pivot + a) % 3;
		cout << char('A' + int(str[b] - 'A' + pivot) % 3) << '\n';
	}
	return 0;
}
