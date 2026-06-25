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
	map<char, char>mm, rev;
	int idx = 0;
	for (char i = 'a'; i <= 'z'; ++i)
	{
		mm[str[idx]] = i;
		rev[i] = str[idx];
		idx++;
	}
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
		for (auto& j : i)
		{
			j = mm[j];
		}
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << rev[j];
		}
		cout << '\n';
	}
	return 0;
}
