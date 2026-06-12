#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<char, int>pic;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<pic>v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = make_pair(str[i], 0);
	}
	int q = 0;
	cin >> q;
	int pivot = 0, p = -1;
	for (int i = 1; i <= q; ++i)
	{
		int a = 0, b = 0;
		char c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			v[b - 1] = make_pair(c, i);
		}
		else if (a == 2)
		{
			pivot = i, p = 0;
		}
		else
		{
			pivot = i, p = 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		char a = char(v[i].first);
		if (v[i].second > pivot || p == -1)
		{
			cout << char(a);
			continue;
		}
		if (p == 0)
		{
			cout << char(tolower(char(a)));
		}
		else
		{
			cout << char(toupper(char(a)));
		}
	}
	return 0;
}
