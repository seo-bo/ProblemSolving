#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, n = 0;
	cin >> h >> w >> n;
	vector<pii> v(n);
	vector<int> A(1), B(1);
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		A.push_back(a), B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	for (auto &[a, b] : v)
	{
		auto x = lower_bound(A.begin(), A.end(), a) - A.begin();
		auto y = lower_bound(B.begin(), B.end(), b) - B.begin();
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
