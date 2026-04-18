#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ld>prefix(n + 1);
	vector<int>a(n + 1), b(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		prefix[i] = prefix[i - 1] + (ld)a[i] / b[i];
		v[i] = v[i - 1] + a[i];
	}
	int idx = lower_bound(prefix.begin() + 1, prefix.end(), prefix[n] / 2) - prefix.begin() - 1;
	cout << fixed << setprecision(10) << v[idx] + (prefix[n] / 2 - prefix[idx]) * b[idx + 1];
	return 0;
}
