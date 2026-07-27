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
	cin >> str;
	for (int i = 0; i + 2 < n; ++i)
	{
		if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
