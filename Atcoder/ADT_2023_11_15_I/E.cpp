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
	map<string, int> mm;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		string temp = str;
		reverse(temp.begin(), temp.end());
		if (mm.find(temp) != mm.end())
		{
			mm[temp]++;
			continue;
		}
		mm[str]++;
	}
	cout << mm.size();
	return 0;
}
