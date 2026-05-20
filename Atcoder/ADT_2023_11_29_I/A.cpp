#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v(3);
	for (auto &i : v)
	{
		cin >> i;
	}
	int pivot = v[1];
	sort(v.begin(), v.end());
	cout << ((pivot == v[1]) ? "Yes" : "No");
	return 0;
}
