#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<int>dq;
	for (int i = 0; i < 5 * n; ++i)
	{
		int a = 0;
		cin >> a;
		dq.push_back(a);
	}
	sort(dq.begin(), dq.end());
	for (int i = 0; i < n; ++i)
	{
		dq.pop_front();
		dq.pop_back();
	}
	int ans = 0;
	for (auto& i : dq)
	{
		ans += i;
	}
	cout << fixed << setprecision(15) << (long double)ans / (3 * n);
	return 0;
}
