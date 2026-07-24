#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'o')
		{
			if (!m)
			{
				str[i] = 'x';
				continue;
			}
			m--;
		}
	}
	cout << str;
	return 0;
}
