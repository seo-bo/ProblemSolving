#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		cout << str;
		if (++mm[str] == 1)
		{
			cout << '\n';
			continue;
		}
		cout << format("({})\n", mm[str] - 1);
	}
	return 0;
}
