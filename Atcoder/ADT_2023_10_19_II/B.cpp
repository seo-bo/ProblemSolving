#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}
