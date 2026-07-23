#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, int>mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		cout << str;
		if (mm.find(str) == mm.end())
		{
			mm[str] = 0;
			cout << '\n';
			continue;
		}
		cout << '(' << ++mm[str] << ')' << '\n';
	}
	return 0;
}
