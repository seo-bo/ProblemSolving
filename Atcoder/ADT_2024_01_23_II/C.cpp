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
	string s, t;
	cin >> s >> t;
	int flag1 = 1, flag2 = 1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != t[i])
		{
			flag1 = 0;
			break;
		}
	}
	for (int i = n - 1, j = m - 1; i >= 0; --i, --j)
	{
		if (s[i] != t[j])
		{
			flag2 = 0;
			break;
		}
	}
	if (!flag1 && !flag2)
	{
		cout << 3;
		return 0;
	}
	if (flag1 && flag2)
	{
		cout << 0;
		return 0;
	}
	if (flag1)
	{
		cout << 1;
		return 0;
	}
	cout << 2;
	return 0;
}
