#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>A(n), B(m);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	ll left = 0, right = INT_MAX, ans = -1;
	auto cal = [&](ll mid)
		{
			ll a = 0, b = 0;
			for (auto& i : A)
			{
				a += (mid >= i);
			}
			for (auto& i : B)
			{
				b += (mid <= i);
			}
			return a >= b;
		};
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
