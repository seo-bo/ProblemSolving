#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pii>v(n);
	vector<bool>ans(n + 1);
	int maxi = 0;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 3; ++j)
		{
			int a = 0;
			cin >> a;
			temp += a;
		}
		maxi = max(maxi, temp);
		v.push_back(make_pair(temp, i));
	}
	sort(v.rbegin(), v.rend());
	int pivot = v[k - 1].first;
	for (auto& [a, b] : v)
	{
		if (a + 300 >= pivot)
		{
			ans[b] = true;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((ans[i]) ? "Yes" : "No") << '\n';
	}
	return 0;
}
