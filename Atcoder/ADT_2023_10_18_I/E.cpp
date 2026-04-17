#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size(), ans = 1;
	for (int i = 1; i < len;)
	{
		int temp = 0;
		while (i < len && str[i] == '0')
		{
			i++, temp++;
		}
		ans += temp / 2, i -= temp % 2;
		if (i < len)
		{
			ans++, i++;
		}
	}
	cout << ans;
	return 0;
}
