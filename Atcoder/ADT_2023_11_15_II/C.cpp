#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string> s;
	int n = 0;
	cin >> n;
	vector<vector<char>> v = {{'H', 'D', 'C', 'S'}, {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}};
	auto cal = [&](string str)
	{
		for (int i = 0; i < 2; ++i)
		{
			int flag = 0;
			for (auto &j : v[i])
			{
				if (str[i] == j)
				{
					flag = 1;
				}
			}
			if (!flag)
			{
				return false;
			}
		}
		return true;
	};
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (!cal(str) || s.find(str) != s.end())
		{
			cout << "No";
			return 0;
		}
		s.insert(str);
	}
	cout << "Yes";
	return 0;
}
