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
	vector<vector<string>>v(n, vector<string>(2));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto cal = [&](int idx, string str)
		{
			for (int i = 0; i < n; ++i)
			{
				if (i == idx)
				{
					continue;
				}
				for (int j = 0; j < 2; ++j)
				{
					if (str == v[i][j])
					{
						return 0;
					}
				}
			}
			return 1;
		};
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 2; ++j)
		{
			temp += cal(i, v[i][j]);
		}
		if (!temp)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
