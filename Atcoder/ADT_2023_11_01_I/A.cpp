#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int x = 2;
	while (x < n)
	{
		x += 4;
	}
	cout << x;
	return 0;
}
