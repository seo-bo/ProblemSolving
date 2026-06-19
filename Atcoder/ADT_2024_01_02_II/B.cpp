#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(10);
	string str;
	cin >> str;
	for (auto& i : str)
	{
		v[i - '0'] = 1;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (!v[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
