#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<int>dq(5 * n);
	for (auto& i : dq)
	{
		cin >> i;
	}
	sort(dq.begin(), dq.end());
	for (int i = 0; i < n; ++i)
	{
		dq.pop_back(), dq.pop_front();
	}
	long double ans = 0;
	for (auto& i : dq)
	{
		ans += i;
	}
	cout << fixed << setprecision(15) << ans / (3 * n);
	return 0;
}
