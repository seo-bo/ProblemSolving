#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, x = 0;
	cin >> a >> b >> x;
	for (int i = a; i != b; i = (i + 1) % 24)
	{
		if (i == x)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
