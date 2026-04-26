#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	sort(str.rbegin(), str.rend());
	int len = str.size();
	ll ans = 0;
	for (int i = 0; i < (1 << len); ++i)
	{
		ll A = 0, B = 0;
		for (int j = 0; j < len; ++j)
		{
			if (i & (1 << j))
			{
				A = A * 10 + (str[j] - '0');
			}
			else
			{
				B = B * 10 + (str[j] - '0');
			}
		}
		ans = max(ans, A * B);
	}
	cout << ans;
	return 0;
}
