#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	if (str.front() == 'M')
	{
		cout << 5;
		return 0;
	}
	if (str.front() == 'W')
	{
		cout << 3;
		return 0;
	}
	if (str.front() == 'F')
	{
		cout << 1;
		return 0;
	}
	cout << ((str.size() == 7) ? 4 : 2);
	return 0;
}
