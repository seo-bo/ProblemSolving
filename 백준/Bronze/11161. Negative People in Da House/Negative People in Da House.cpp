#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		int ans = 0, cur = 0;
		for (int i = 0; i < n; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			cur += a - b;
			if (cur < 0)
			{
				ans += -cur;
				cur = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}