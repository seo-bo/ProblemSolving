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
	vector<int> v(3);
	for (int i = 0; i < n; ++i)
	{
		int a = str[i] - 'A';
		v[a]++;
		int flag = 1;
		for (int j = 0; j < 3; ++j)
		{
			if (!v[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}
