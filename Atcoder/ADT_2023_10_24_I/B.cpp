#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	string base = "aeiou";
	for (auto& i : str)
	{
		int f = 1;
		for (auto& j : base)
		{
			if (i == j)
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			cout << i;
		}
	}
	return 0;
}
