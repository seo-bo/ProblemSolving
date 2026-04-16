#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	for (int i = 0; i < 9; ++i)
	{
		if (str[i] != char(i + '0'))
		{
			cout << i;
			return 0;
		}
	}
	cout << 9;
	return 0;
}
