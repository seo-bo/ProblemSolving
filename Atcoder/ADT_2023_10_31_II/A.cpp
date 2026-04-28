#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	map<char, int>mm;
	for (auto& i : str)
	{
		mm[i]++;
	}
	for (auto& [a, b] : mm)
	{
		if (b == 1)
		{
			cout << a;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
