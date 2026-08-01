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
	int y = str.back() - '0';
	for (int i = 0; str[i] != '.'; ++i)
	{
		cout << str[i];
	}
	if (y <= 2)
	{
		cout << '-';
	}
	else if (y >= 7)
	{
		cout << '+';
	}
	return 0;
}
