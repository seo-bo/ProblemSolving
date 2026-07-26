#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 1; i < len; i += 2)
	{
		if (str[i] == '1')
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
