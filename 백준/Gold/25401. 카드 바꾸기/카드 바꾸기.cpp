#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	unordered_map<int, int>mm;
	vector<int>v(n);
	int pivot = 0;
	for (auto& i : v)
	{
		cin >> i;
		mm[i]++;
		pivot = max(pivot, mm[i]);
	}
	int ans = n - pivot;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int temp = 0;
			int pivot = v[j] - v[i];
			if (pivot % (j - i))
			{
				continue;
			}
			pivot /= (j - i);
			int cur = v[i] - pivot;
			for (int k = i - 1; k >= 0; --k)
			{
				if (cur != v[k])
				{
					temp++;
				}
				cur -= pivot;
			}
			cur = v[i] + pivot;
			for (int k = i + 1; k < n; ++k)
			{
				if (cur != v[k])
				{
					temp++;
				}
				cur += pivot;
			}
			ans = min(ans, temp);
		}
	}
	cout << ans;
	return 0;
}