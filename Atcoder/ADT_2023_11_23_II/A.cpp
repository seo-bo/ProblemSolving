#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v(4);
	string str;
	cin >> str;
	for (int i = 0; i < 4; ++i)
	{
		if (i + 1 < 4)
		{
			v[i + 1] += (str[i] == '1');
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		cout << min(v[i], 1);
	}
	return 0;
}
