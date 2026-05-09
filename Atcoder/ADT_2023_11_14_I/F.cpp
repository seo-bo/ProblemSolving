#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v(m);
	for (auto &i : v)
	{
		cin >> i;
	}
	for (int i = 1; i <= n; ++i)
	{
		auto it = lower_bound(v.begin(), v.end(), i);
		cout << *it - i << '\n';
	}
	return 0;
}
