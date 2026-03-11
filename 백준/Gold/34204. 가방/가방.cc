#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, c = 0;
	cin >> n >> k >> c;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<ll>prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + v[i - 1];
	}
	int right = 0;
	for (int i = 1; i <= c; ++i)
	{
		while (right < n && prefix[right + 1] <= i)
		{
			right++;
		}
		int a = min(n, right + k), b = a - k;
		cout << prefix[a] - prefix[b] << '\n';
	}
	return 0;
}