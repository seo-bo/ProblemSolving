#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 다른 i,j
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>str(n);
	for (auto& i : str)
	{
		cin >> i;
	}
	for (auto& i : str)
	{
		for (auto& j : str)
		{
			if (i == j)
			{
				continue;
			}
			string temp = i + j;
			int len = temp.size(), flag = 1;
			for (int i = 0; i < len; ++i)
			{
				if (temp[i] != temp[len - i - 1])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
