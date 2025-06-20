#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 아 중앙값;
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>ans(n);
	int left = n / 2 - 1, right = n / 2 + 1;
	int cnt = n - 1;
	ans[n / 2] = n;
	while (left >= 0 || right <= n - 1)
	{
		if (left >= 0)
		{
			ans[left] = cnt--;
		}
		if (right <= n - 1)
		{
			ans[right] = cnt--;
		}
		left--;
		right++;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}