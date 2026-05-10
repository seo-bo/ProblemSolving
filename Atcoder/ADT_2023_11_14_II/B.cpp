#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int pre = 0;
	cin >> pre;
	for (int i = 2; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a - pre <= k)
		{
			cout << a;
			return 0;
		}
		pre = a;
	}
	cout << -1;
	return 0;
}
