#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 1, right = LLONG_MAX / 4, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (auto& i : v)
		{
			pivot += min(i, mid);
		}
		if (pivot >= k)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	vector<ll>res = v;
	ll diff = 0;
	for (int i = 0; i < n; ++i)
	{
		ll p = min(ans, v[i]);
		diff += p;
		res[i] = v[i] - p;
	}
	for (int i = n - 1; i >= 0 && diff > k; --i)
	{
		if (v[i] >= ans)
		{
			diff--;
			res[i]++;
		}
	}
	for (auto& i : res)
	{
		cout << i << ' ';
	}
	return 0;
}
