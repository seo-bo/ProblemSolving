#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	for (int i = min(k, n); i < n; ++i)
	{
		cout << v[i] << ' ';
	}
	for (int i = 0; i < min(k, n); ++i)
	{
		cout << 0 << ' ';
	}
	return 0;
}
