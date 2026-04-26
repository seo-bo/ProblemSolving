#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 1; i <= len / 2; ++i)
	{
		swap(str[2 * i - 2], str[2 * i - 1]);
	}
	cout << str;
	return 0;
}
