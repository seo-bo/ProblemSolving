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
	string base = "aeiou";
	for (auto& i : str)
	{
		int flag = 1;
		for (auto& j : base)
		{
			if (i == j)
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			continue;
		}
		cout << i;
	}
	return 0;
}
