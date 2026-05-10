#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<char, char> mm, rev;
	string str;
	cin >> str;
	char p = 'a';
	for (auto &i : str)
	{
		mm[i] = p;
		rev[p] = i;
		p++;
	}
	int n = 0;
	cin >> n;
	vector<string> v(n);
	for (auto &i : v)
	{
		cin >> i;
		for (auto &j : i)
		{
			j = mm[j];
		}
	}
	sort(v.begin(), v.end());
	for (auto &i : v)
	{
		for (auto &j : i)
		{
			cout << rev[j];
		}
		cout << '\n';
	}
	return 0;
}
