#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'o')
		{
			continue;
		}
		int flag = 1;
		for (int j = -1; j <= 1; j += 2)
		{
			int nx = i + j;
			if (nx < 0 || nx >= n || str[nx] == 'x')
			{
				continue;
			}
			flag = 0;
			break;
		}
		ans += flag;
	}
	cout << ans;
	return 0;
}
