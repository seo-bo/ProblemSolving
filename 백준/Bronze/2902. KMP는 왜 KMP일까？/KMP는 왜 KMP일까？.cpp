#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int f = 1;
	for (auto& i : str)
	{
		if (f == 1)
		{
			if (i == '-')
			{
				continue;
			}
			else
			{
				cout << i;
				f = 0;
			}
		}
		else
		{
			if (i == '-')
			{
				f = 1;
			}
		}
	}
	return 0;
}