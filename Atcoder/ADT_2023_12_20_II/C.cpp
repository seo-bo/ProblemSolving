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
	int f1 = 0, f2 = 0, len = str.size();
	set<char> s;
	for (auto &i : str)
	{
		f1 |= ('a' <= i && i <= 'z');
		f2 |= ('A' <= i && i <= 'Z');
		s.insert(i);
	}
	cout << ((f1 && f2 && s.size() == len) ? "Yes" : "No");
	return 0;
}
