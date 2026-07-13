#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<char, int>mm;
	string str;
	cin >> str;
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
