#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int lim = (n + 1) / 2;
	int a = n, b = 1;
	while (a > b)
	{
		cout << a-- << ' ';
		cout << b++ << ' ';
	}
	if (n % 2)
	{
		cout << a;
	}
	return 0;
}