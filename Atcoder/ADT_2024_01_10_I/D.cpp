#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>A = { 0,4,3,5,2,4,6,1,3,5,7 };
	vector<int>cnt = { 0,1,1,2,2,2,1,1 };
	string str;
	cin >> str;
	if (str.front() == '1')
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (str[i] == '0')
		{
			cnt[A[i + 1]]--;
		}
	}
	for (int i = 1; i <= 7; ++i)
	{
		for (int j = 1 + 1; j <= 7; ++j)
		{
			if (cnt[i] && cnt[j] && j - i >= 2)
			{
				int flag = 0;
				for (int k = i + 1; k <= j - 1; ++k)
				{
					flag |= (cnt[k]);
				}
				if (!flag)
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
