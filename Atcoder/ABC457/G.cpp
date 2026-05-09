#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

/*
* Ti - Tj <= |Xi - Xj|
* (1) Ti - Tj <= Xi - Xj
* (2) Ti - Tj <= -Xi + Xj
* (1) Ti - Xi <= Tj - Xj
* (2) Ti + Xi <= Tj + Xj
* A = T - X / B = T + X
* -> Ai <= Aj && Bi <= Bj
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		int t = 0, x = 0;
		cin >> t >> x;
		a = t - x, b = t + x;
	}
	sort(v.begin(), v.end());
	vector<int>s;
	for (auto& [a, b] : v)
	{
		auto it = lower_bound(s.begin(), s.end(), -b);
		if (it == s.end())
		{
			s.push_back(-b);
			continue;
		}
		*it = -b;
	}
	cout << s.size();
	return 0;
}
