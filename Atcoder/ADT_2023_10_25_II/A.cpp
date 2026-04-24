#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n <= 125)
	{
		cout << 4;
		return 0;
	}
	if (n <= 211)
	{
		cout << 6;
		return 0;
	}
	cout << 8;
	return 0;
}
