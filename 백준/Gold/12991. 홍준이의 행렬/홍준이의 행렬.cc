#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>A(n), B(n);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	sort(B.begin(), B.end());
	auto cal = [&](ll mid)
		{
			int cnt = 0;
			for (auto& i : A)
			{
				ll pivot = mid / i;
				cnt += upper_bound(B.begin(), B.end(), pivot) - B.begin();
			}
			return (cnt >= k);
		};
	ll left = 1, right = LLONG_MAX / 8, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}