#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, c = 0;
	cin >> n >> c;
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (--c == 0)
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
