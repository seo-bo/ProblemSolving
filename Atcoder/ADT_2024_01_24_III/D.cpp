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
	int len = str.size();
	auto cal = [&](int idx)
		{
			for (int i = 0; i < len; ++i)
			{
				if (base[idx] != str[i])
				{
					return false;
				}
				idx = (idx + 1) % 3;
			}
			return true;
		};
	for (int i = 0; i < 3; ++i)
	{
		if (cal(i))
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
