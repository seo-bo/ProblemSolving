#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = 1; i <= 2;++i)
	{
		for (int j = 1; j <= 2; ++j)
		{
			int c = 0;
			cin >> c;
			if (a == i && b == j)
			{
				cout << c;
				return 0;
			}
		}
	}
	return 0;
}
