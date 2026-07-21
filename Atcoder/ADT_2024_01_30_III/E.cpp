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
	vector<int>zero, odd, even;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (!a)
		{
			zero.push_back(a);
			continue;
		}
		if (a % 2)
		{
			odd.push_back(a);
			continue;
		}
		even.push_back(a);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	int ans = -1;
	if (zero.size() >= 2)
	{
		ans = 0;
	}
	if (odd.size() >= 2)
	{
		int len = odd.size();
		ans = max(ans, odd[len - 1] + odd[len - 2]);
	}
	if (even.size() >= 2)
	{
		int len = even.size();
		ans = max(ans, even[len - 1] + even[len - 2]);
	}
	if (!zero.empty() && !even.empty())
	{
		ans = max(ans, even.back());
	}
	cout << ans;
	return 0;
}
