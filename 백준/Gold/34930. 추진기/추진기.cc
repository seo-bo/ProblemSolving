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
		int l = 0, r = 0;
		cin >> l >> r;
		int p = max(l, (r + 1) / 2);
		cout << p << ' ';
		for (int i = r, f = 1; i >= l; --i)
		{
			if (i == p)
			{
				continue;
			}
			cout << i * ((f) ? -1 : 1) << ' ';
			f ^= 1;
		}
		cout << '\n';
	}
	return 0;
}