#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string>s = { "ABC","ARC","AGC","AHC" };
	int mask = 0;
	for (int i = 0; i < 3; ++i)
	{
		string str;
		cin >> str;
		s.erase(str);
	}
	cout << *s.begin();
	return 0;
}
