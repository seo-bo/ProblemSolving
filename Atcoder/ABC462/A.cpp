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
	for (auto& i : str)
	{
		if ('0' <= i && i <= '9')
		{
			cout << i;
		}
	}
	return 0;
}
