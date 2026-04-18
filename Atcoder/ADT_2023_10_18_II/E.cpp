#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// kpka

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int left = 0, right = str.size() - 1, flag = 0;
	while (left <= right)
	{
		if (str[left] != str[right])
		{
			if (str[right] == 'a')
			{
				if (flag)
				{
					cout << "No";
					return 0;
				}
				right--;
			}
			else
			{
				cout << "No";
				return 0;
			}
		}
		else
		{
			flag |= (str[left] != 'a');
			left++, right--;
		}
	}
	cout << "Yes";
	return 0;
}
