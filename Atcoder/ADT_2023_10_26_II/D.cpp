#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 1; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i + j >= n || str[j] == str[i + j])
			{
				break;
			}
			temp = j + 1;
		}
		cout << temp << '\n';
	}
	return 0;
}
