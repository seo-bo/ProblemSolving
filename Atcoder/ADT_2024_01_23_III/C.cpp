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
	if (str.size() != 8)
	{
		cout << "No";
		return 0;
	}
	for (auto& i : { str.front(),str.back() })
	{
		if ('A' > i || i > 'Z')
		{
			cout << "No";
			return 0;
		}
	}
	if ('1' > str[1] || str[1] > '9')
	{
		cout << "No";
		return 0;
	}
	for (int i = 2; i <= 6; ++i)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			continue;
		}
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}
