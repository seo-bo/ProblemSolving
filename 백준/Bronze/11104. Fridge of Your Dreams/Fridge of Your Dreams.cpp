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
		string str;
		cin >> str;
		ll ans = 0;
		int len = str.size();
		for (ll i = len - 1, j = 0; i >= 0; --i, ++j)
		{
			if (str[i] == '1')
			{
				ans += (1LL << j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}