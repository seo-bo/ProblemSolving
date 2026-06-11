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
	set<int> odd, even;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a % 2)
		{
			odd.insert(a);
		}
		else
		{
			even.insert(a);
		}
	}
	auto cal = [&](set<int> &s)
	{
		if (s.size() <= 1)
		{
			return -1;
		}
		auto it = prev(s.end());
		return *it + *(prev(it));
	};
	int ans1 = cal(odd), ans2 = cal(even);
	cout << max(ans1, ans2);
	return 0;
}
