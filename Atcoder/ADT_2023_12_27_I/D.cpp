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
	vector<vector<int>>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			v[i].push_back(b);
		}
		sort(v[i].begin(), v[i].end());
	}
	int x = 0;
	cin >> x;
	int pivot = INT_MAX;
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (binary_search(v[i].begin(), v[i].end(), x))
		{
			int len = v[i].size();
			if (pivot > len)
			{
				pivot = len;
				ans.clear();
				ans.push_back(i);
			}
			else if (pivot == len)
			{
				ans.push_back(i);
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
