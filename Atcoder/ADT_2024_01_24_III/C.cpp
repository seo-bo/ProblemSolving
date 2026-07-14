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
	int base = str.front() - '0', flag = 1;
	for (auto& i : str)
	{
		if (i - '0' != base)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << "Weak";
		return 0;
	}
	base = (base - 1 + 10) % 10;
	for (auto& i : str)
	{
		int nxt = (base + 1) % 10;
		if (nxt == i - '0')
		{
			base = nxt;
			continue;
		}
		cout << "Strong";
		return 0;
	}
	cout << "Weak";
	return 0;
}
