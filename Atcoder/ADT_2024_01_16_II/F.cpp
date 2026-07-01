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
	vector<int> a(n), b(m), v;
	for (auto &i : a)
	{
		cin >> i;
		v.push_back(i);
	}
	for (auto &i : b)
	{
		cin >> i;
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	for (auto &i : a)
	{
		cout << lower_bound(v.begin(), v.end(), i) - v.begin() + 1 << ' ';
	}
	cout << '\n';
	for (auto &i : b)
	{
		cout << lower_bound(v.begin(), v.end(), i) - v.begin() + 1 << ' ';
	}
	return 0;
}
