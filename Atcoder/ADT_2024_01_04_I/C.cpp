#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			string temp = v[i] + v[j];
			int len = temp.size(), flag = 1;
			for (int k = 0; k < len / 2 && flag; ++k)
			{
				flag &= (temp[k] == temp[len - k - 1]);
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
