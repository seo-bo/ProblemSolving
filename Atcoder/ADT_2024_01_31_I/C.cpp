#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int slen = s.size(), tlen = t.size();
	for (int i = 0; i + tlen <= slen; ++i)
	{
		int flag = 1;
		for (int j = 0; j < tlen; ++j)
		{
			if (s[i + j] != t[j])
			{
				flag = 0;
				break;
			}
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
