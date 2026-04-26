#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int a = n - n % 5;
	cout << ((n % 5 <= 2) ? a : a + 5);
	return 0;
}
