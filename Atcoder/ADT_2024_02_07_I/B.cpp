#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	string str;
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			str += i;
		}
	}
	cout << str[x - 1];
	return 0;
}
