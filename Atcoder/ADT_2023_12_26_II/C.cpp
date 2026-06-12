#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			char a;
			cin >> a;
			if (a == '*')
			{
				cout << char(j - 1 + 'a') << 8 - i + 1;
				return 0;
			}
		}
	}
	return 0;
}
