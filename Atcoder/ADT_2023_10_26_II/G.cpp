#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	string str;
	cin >> str;
	vector<char>v;
	for (auto& i : str)
	{
		if (i == 'U')
		{
			if (v.empty())
			{
				x /= 2;
			}
			else
			{
				v.pop_back();
			}
			continue;
		}
		v.push_back(i);
	}
	for (auto& i : v)
	{
		if (i == 'R')
		{
			x = x * 2 + 1;
		}
		else
		{
			x *= 2;
		}
	}
	cout << x;
	return 0;
}
