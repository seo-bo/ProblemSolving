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
	vector<ll> A(n), B(m);
	for (auto &i : A)
	{
		cin >> i;
	}
	for (auto &i : B)
	{
		cin >> i;
	}
	ll left = 1, right = INT_MAX, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		int a = 0, b = 0;
		for (auto &i : A)
		{
			a += (mid >= i);
		}
		for (auto &i : B)
		{
			b += (mid <= i);
		}
		if (a >= b)
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
