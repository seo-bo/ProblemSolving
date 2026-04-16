#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int base = 1260 + n;
	int p = base % 60;
	cout << base / 60 << ":";
	if (p / 10 == 0)
	{
		cout << 0;
	}
	cout << p;
	return 0;
}
