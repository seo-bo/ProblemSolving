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
	int a = 7, mask = 0;
	for (int i = 0; i < n; ++i)
	{
		int p = str[i] - 'A';
		mask |= (1 << p);
		if (a == mask)
		{
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}
