#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base = "ACE、BDF、CEG、DFA、EGB、FAC、GBD";
	string str;
	cin >> str;
	int len = base.size();
	for (int i = 0; i + 2 < len; ++i)
	{
		int flag = 1;
		for (int j = 0; j <= 2; ++j)
		{
			if (str[j] == base[i + j])
			{
				continue;
			}
			flag = 0;
			break;
		}
		if (flag)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
