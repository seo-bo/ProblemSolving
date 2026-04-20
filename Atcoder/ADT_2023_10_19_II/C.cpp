#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	set<char>s;
	int f1 = 0, f2 = 0;
	for (auto& i : str)
	{
		if ('A' <= i && i <= 'Z')
		{
			f1 = 1;
		}
		else
		{
			f2 = 1;
		}
		s.insert(i);
	}
	cout << ((s.size() == len && f1 && f2) ? "Yes" : "No");
	return 0;
}
