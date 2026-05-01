#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			char a = 0;
			cin >> a;
			if (a == '*')
			{
				cout << char('a' + j - 1) << 8 - i + 1;
				return 0;
			}
		}
	}
	return 0;
}
