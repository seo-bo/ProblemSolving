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
	if (str[0] == 'M')
	{
		cout << 5;
	}
	else if (str[0] == 'W')
	{
		cout << 3;
	}
	else if (str[0] == 'F')
	{
		cout << 1;
	}
	else
	{
		if (str[1] == 'u')
		{
			cout << 4;
		}
		else
		{
			cout << 2;
		}
	}
	return 0;
}
