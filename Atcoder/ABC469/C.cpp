#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'x')
		{
			v.push_back(i + 1);
		}
	}
	int len = v.size();
	for (int i = 0; i < n; ++i)
	{
		if (i < len)
		{
			cout << v[i] << '\n';
			continue;
		}
		cout << n << '\n';
	}
	return 0;
}
