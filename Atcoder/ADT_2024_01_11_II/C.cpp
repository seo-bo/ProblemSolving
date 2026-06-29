#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string>s = { "ABC","ARC","AGC","AHC" };
	for (int i = 0; i < 3; ++i)
	{
		string str;
		cin >> str;
		s.erase(str);
	}
	cout << *s.begin();
	return 0;
}
