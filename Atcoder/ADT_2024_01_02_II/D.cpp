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
	int len = s.size();
	if (len > t.size())
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < len; ++i)
	{
		if (s[i] != t[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
