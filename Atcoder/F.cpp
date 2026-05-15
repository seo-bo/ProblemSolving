#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<string> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	vector<int> per(n);
	iota(per.begin(), per.end(), 0);
	do
	{
		int flag = 1;
		for (int i = 1; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < m; ++j)
			{
				cnt += (v[per[i - 1]][j] != v[per[i]][j]);
			}
			flag &= (cnt == 1);
		}
		if (flag)
		{
			cout << "Yes";
			return 0;
		}
	} while (next_permutation(per.begin(), per.end()));
	cout << "No";
	return 0;
}
