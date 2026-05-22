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
	for (auto &i : str)
	{
		cout << ((i == '0') ? '1' : '0');
	}
	return 0;
}
