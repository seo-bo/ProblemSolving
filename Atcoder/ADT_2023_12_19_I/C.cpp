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
	int len = str.size();
	if (len == 8 && 'A' <= str.front() && str.front() <= 'Z' && 'A' <= str.back() && str.back() <= 'Z')
	{
		int a = 0;
		for (int i = 1; i <= 6; ++i)
		{
			if ('0' <= str[i] && str[i] <= '9')
			{
				a = a * 10 + str[i] - '0';
				continue;
			}
			cout << "No";
			return 0;
		}
		if (100000 <= a && a <= 999999)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
