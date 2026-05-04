#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>mul(1e6 + 2);
	mul[0] = 1;
	for (int i = 1; i <= (int)1e6; ++i)
	{
		mul[i] = (mul[i - 1] * 26) % MOD;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int len = 0;
		cin >> len;
		string str;
		cin >> str;
		ll ans = 0;
		for (int i = 0, co = (len + 1) / 2 - 1; i < (len + 1) / 2; ++i, --co)
		{
			ll pivot = str[i] - 'A';
			ans = (ans + pivot * mul[co]) % MOD;
		}
		int f = 1;
		for (int i = (len + 1) / 2; i < len; ++i)
		{
			char a = str[len - i - 1];
			if (a == str[i])
			{
				continue;
			}
			f &= (a < str[i]);
			break;
		}
		cout << (ans + f) % MOD << '\n';
	}
	return 0;
}
