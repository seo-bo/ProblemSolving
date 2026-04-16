#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	vector<char>s;
	int open = 0;
	for (auto& i : str)
	{
		if (i == '(')
		{
			open++;
			s.push_back(i);
		}
		else if (i == ')')
		{
			if (!open)
			{
				s.push_back(i);
			}
			else
			{
				while (!s.empty() && s.back() != '(')
				{
					s.pop_back();
				}
				s.pop_back();
				open--;
			}
		}
		else
		{
			s.push_back(i);
		}
	}
	for (auto& i : s)
	{
		cout << i;
	}
	return 0;
}
