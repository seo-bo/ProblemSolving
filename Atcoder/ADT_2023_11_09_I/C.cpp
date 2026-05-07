#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int pre = 0, n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (pre < a)
		{
			pre = a;
		}
		else
		{
			break;
		}
	}
	cout << pre;
	return 0;
}
