#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<string> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	map<string, int> mm;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		mm[str]++;
	}
	for (auto &i : v)
	{
		if (mm.find(i) == mm.end())
		{
			cout << "No\n";
			continue;
		}
		if (--mm[i] == 0)
		{
			mm.erase(i);
		}
		cout << "Yes\n";
	}
	return 0;
}
