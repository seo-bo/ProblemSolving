#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string> s = {"and", "not", "that", "the", "you"};
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end())
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
