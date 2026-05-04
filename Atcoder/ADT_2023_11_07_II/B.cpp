#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int now = 0, maxi = 0, cnt = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (!i)
		{
			now = a;
		}
		if (maxi == a)
		{
			cnt++;
		}
		else if (maxi < a)
		{
			maxi = a;
			cnt = 1;
		}
	}
	if (now == maxi)
	{
		if (cnt == 1)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << 1;
			return 0;
		}
	}
	cout << maxi - now + 1;
	return 0;
}
