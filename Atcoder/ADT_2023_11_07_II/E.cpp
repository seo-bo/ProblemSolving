#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int a = 0;
	cin >> a;
	do
	{
		if (--a == 0)
		{
			cout << str;
			return 0;
		}
	} while (next_permutation(str.begin(), str.end()));
	return 0;
}
