#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	a = abs(8 - a), b = abs(8 - b);
	cout << ((max(a, b) % 2) ? "black" : "white");
	return 0;
}
