#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str, base = ".,";
	cin >> str;
	int idx = 0;
	for (auto &i : str)
	{
		if (i == '\"')
		{
			idx ^= 1;
		}
		if (i == ',')
		{
			i = base[idx];
		}
	}
	cout << str;
	return 0;
}
