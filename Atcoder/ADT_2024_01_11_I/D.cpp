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
	for (int i = 0; i + 1 < len; ++i)
	{
		swap(s[i], s[i + 1]);
		if (s == t)
		{
			cout << "Yes";
			return 0;
		}
		swap(s[i], s[i + 1]);
	}
	cout << ((s == t) ? "Yes" : "No");
	return 0;
}
