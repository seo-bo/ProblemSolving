#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>per = { {0},{7},{4},{8,2},{5,1},{9,3},{6},{10} };
	string str;
	cin >> str;
	vector<int>cnt(9);
	if (str.front() == '1')
	{
		cout << "No";
		return 0;
	}
	for (int i = 1; i <= 10; ++i)
	{
		int p = int(str[i - 1] - '0');
		int f = 0;
		for (int j = 1; j <= 7 && !f; ++j)
		{
			for (auto& k : per[j])
			{
				if (i == k)
				{
					f = j;
					break;
				}
			}
		}
		cnt[f] += p;
	}
	for (int i = 1; i <= 7; ++i)
	{
		for (int j = i + 1; j <= 7; ++j)
		{
			if (!cnt[i] || !cnt[j])
			{
				continue;
			}
			for (int k = i + 1; k < j; ++k)
			{
				if (!cnt[k])
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}
