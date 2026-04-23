
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	if (a == 0)
	{
		cout << "Silver";
	}
	else if (b == 0)
	{
		cout << "Gold";
	}
	else
	{
		cout << "Alloy";
	}
	return 0;
}
