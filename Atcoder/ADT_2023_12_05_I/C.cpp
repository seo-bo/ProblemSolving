#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i)
	{
		auto &[a, b] = v[i];
		cin >> a;
		b = i;
	}
	sort(v.begin(), v.end());
	v.pop_back();
	cout << v.back().second + 1;
	return 0;
}
