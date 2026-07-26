#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int ans = 0, len = str.size();
	for (int left = 0; left < len; ++left)
	{
		for (int right = left; right < len; ++right)
		{
			int flag = 1;
			int l = left, r = right;
			while (l < r)
			{
				if (str[l] != str[r])
				{
					flag = 0;
					break;
				}
				l++, r--;
			}
			if (flag)
			{
				ans = max(ans, right - left + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
