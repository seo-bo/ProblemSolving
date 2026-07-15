#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int p = 0, left = -1, mid = -1, right = -1, len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == 'B')
		{
			p = (p + i) % 2;
		}
		if (str[i] == 'R')
		{
			if (left == -1)
			{
				left = i;
			}
			else
			{
				right = i;
			}
		}
		if (str[i] == 'K')
		{
			mid = i;
		}
	}
	cout << ((p && left < mid && mid < right) ? "Yes" : "No");
	return 0;
}
