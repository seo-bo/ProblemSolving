#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	for (int i = 0, j = 0; j < 6; ++j, i = (i + 1) % str.size())
	{
		cout << str[i];
	}
	return 0;
}
