#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str = "atcoder";
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = a - 1; i < b; ++i)
	{
		cout << str[i];
	}
	return 0;
}
