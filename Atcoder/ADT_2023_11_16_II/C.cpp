#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<string> v(4);
	for (int i = 1; i <= 3; ++i)
	{
		cin >> v[i];
	}
	string str;
	cin >> str;
	for (auto &i : str)
	{
		int a = i - '0';
		cout << v[a];
	}
	return 0;
}
