#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n - 1; ++i)
	{
		char a = str[i], b = str[i + 1];
		if ((a == 'a' && b == 'b') || (a == 'b' && b == 'a'))
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
