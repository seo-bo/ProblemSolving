#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, r = 0, c = 0;
	cin >> h >> w >> r >> c;
	int ans = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (abs(i - r) + abs(j - c) == 1)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
