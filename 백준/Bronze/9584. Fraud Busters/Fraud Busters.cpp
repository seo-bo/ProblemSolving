#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<string>s;
	int n = 0, len = str.size();
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		auto sv = [&]
			{
				for (int j = 0; j < len; ++j)
				{
					if (str[j] == '*')
					{
						continue;
					}
					if (str[j] != temp[j])
					{
						return false;
					}
				}
				return true;
			};
		if (sv())
		{
			s.push_back(temp);
		}
	}
	cout << s.size() << '\n';
	for (auto& i : s)
	{
		cout << i << '\n';
	}
	return 0;
}