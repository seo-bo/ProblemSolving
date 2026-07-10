#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i - 1];
		cin >> a;
		b = i;
	}
	sort(v.begin(), v.end());
	cout << v[n - 2].second;
	return 0;
}
