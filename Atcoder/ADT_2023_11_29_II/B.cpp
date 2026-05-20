#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	int a = 0, b = 0, c = 0;
	for (auto &i : str)
	{
		if (i == 'T')
		{
			if (++a > b)
			{
				c = 1;
			}
		}
		if (i == 'A')
		{
			if (++b > a)
			{
				c = 0;
			}
		}
	}
	cout << (((a > b) || (a == b && c)) ? "T" : "A");
	return 0;
}
