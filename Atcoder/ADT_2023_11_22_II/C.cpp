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
	vector<string> v(k);
	for (auto &i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (auto &i : v)
	{
		cout << i << '\n';
	}
	return 0;
}
