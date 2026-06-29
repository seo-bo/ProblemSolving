#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<int>v(n - 1);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 100; ++i)
	{
		vector<int>temp = v;
		temp.push_back(i);
		sort(temp.begin(), temp.end());
		int tot = 0;
		for (int j = 1; j < n - 1; ++j)
		{
			tot += temp[j];
		}
		if (tot >= x)
		{
			ans = min(ans, i);
		}
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
