#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	while (q--)
	{
		int a = 0;
		cin >> a;
		int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
		cout << n - idx << '\n';
	}
	return 0;
}
