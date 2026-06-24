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
	vector<char>v;
	for (auto& i : str)
	{
		if (i == 'a' && !v.empty() && v.back() == 'n')
		{
			v.push_back('y');
			v.push_back('a');
			continue;
		}
		v.push_back(i);
	}
	for (auto& i : v)
	{
		cout << i;
	}
	return 0;
}
