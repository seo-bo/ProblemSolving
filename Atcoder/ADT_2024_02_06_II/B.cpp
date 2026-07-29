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
	for (int i = len; i < 4; ++i)
	{
		cout << 0;
	}
	cout << str;
	return 0;
}
