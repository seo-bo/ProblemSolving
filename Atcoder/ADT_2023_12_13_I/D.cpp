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
	auto palin = [&](string str)
	{
		int len = str.size();
		for (int i = 0; i < len / 2; ++i)
		{
			if (str[i] != str[len - i - 1])
			{
				return false;
			}
		}
		return true;
	};
	int ans = 1;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		string temp;
		for (int j = i; j < len; ++j)
		{
			temp += str[j];
			if (palin(temp))
			{
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
