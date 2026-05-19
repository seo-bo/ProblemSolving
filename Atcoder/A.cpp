#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	auto cal = [&](int a)
	{
		if (a >= 10)
		{
			str += char(a - 10 + 'A');
		}
		else
		{
			str += char(a + '0');
		}
	};
	while (n >= 16)
	{
		cal(n / 16);
		n %= 16;
	}
	cal(n);
	int len = str.size();
	for (int i = 0; i < 2 - len; ++i)
	{
		cout << 0;
	}
	cout << str;
	return 0;
}
