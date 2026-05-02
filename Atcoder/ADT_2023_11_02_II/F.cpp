#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll sum = 0;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	sort(v.begin(), v.end());
	ll ans = 0, pivot = sum / n;
	vector<ll>ok(n);
	for (int i = 0; i < n; ++i)
	{
		ok[i] = pivot - v[i];
		sum -= pivot;
	}
	for (int i = n - 1; i >= 0 && sum; --i, --sum)
	{
		ok[i]++;
	}
	for (auto& i : ok)
	{
		ans += llabs(i);
	}
	cout << ans / 2;
	return 0;
}
