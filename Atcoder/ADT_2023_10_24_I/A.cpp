#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 1000; i; i /= 10)
	{
		cout << n / i;
		n %= i;
	}
	return 0;
}
