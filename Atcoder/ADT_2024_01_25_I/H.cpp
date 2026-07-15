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
	int len = str.size();
	ll n = stoll(str), ans = LLONG_MAX;
	for (char i = '1'; i <= '9'; ++i)
	{
		string temp(len, i);
		ll p = stoll(temp);
		if (n <= p)
		{
			ans = p;
			break;
		}
	}
	if (ans == LLONG_MAX)
	{
		string temp(len + 1, '1');
		ans = stoll(temp);
	}
	for (int i = 1; i <= 9; ++i) // 맨 앞자리수
	{
		for (int j = -9; j <= 9; ++j) // 공차
		{
			if (!j)
			{
				continue;
			}
			ll temp = 0;
			for (int k = 0, nxt = 0; k < len; ++k, ++nxt)
			{
				ll sum = i + nxt * j;
				if (sum < 0 || sum > 9)
				{
					temp = LLONG_MAX;
					break;
				}
				temp = temp * 10 + i + nxt * j;
			}
			if (temp >= n)
			{
				ans = min(ans, temp);
			}
		}
	}
	cout << ans;
	return 0;
}
