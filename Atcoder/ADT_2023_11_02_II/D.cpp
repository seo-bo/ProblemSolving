#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	for (auto& i : { str.front(),str.back() })
	{
		if ('A' <= i && i <= 'Z')
		{
			continue;
		}
		cout << "No";
		return 0;
	}
	int len = str.size(), res = 0;
	if (len != 8)
	{
		cout << "No";
		return 0;
	}
	for (int i = 1; i < len - 1; ++i)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			continue;
		}
		cout << "No";
		return 0;
	}
	cout << ((100000 <= res && res <= 999999) ? "Yes" : "No");
	return 0;
}
