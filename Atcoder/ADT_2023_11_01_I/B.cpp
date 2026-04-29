#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int ans = -1, pivot = INT_MIN;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (pivot < a)
		{
			ans = i, pivot = a;
		}
	}
	cout << ans;
	return 0;
}
