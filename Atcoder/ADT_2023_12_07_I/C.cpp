#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str, base = "oxx";
	cin >> str;
	for (int i = 0; i < 3; ++i)
	{
		int flag = 1, idx = i;
		for (auto &j : str)
		{
			if (base[idx] != j)
			{
				flag = 0;
				break;
			}
			idx = (idx + 1) % 3;
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
