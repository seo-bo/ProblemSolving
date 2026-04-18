#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if (i + j * 3 == c)
			{
				ans = min(ans, i * a + j * b);
			}
		}
	}
	cout << ans;
	return 0;
}
