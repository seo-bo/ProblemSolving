#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll l = 0, n = 0, m = 0;
	cin >> l >> n >> m;
	deque<pll> A, B;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		A.push_back(make_pair(a, b));
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		B.push_back(make_pair(a, b));
	}
	ll ans = 0;
	while (!A.empty())
	{
		auto &[an, acnt] = A.front();
		auto &[bn, bcnt] = B.front();
		int flag = (an == bn);
		ll mini = min(acnt, bcnt);
		ans += mini * flag;
		acnt -= mini, bcnt -= mini;
		if (!acnt)
		{
			A.pop_front();
		}
		if (!bcnt)
		{
			B.pop_front();
		}
	}
	cout << ans;
	return 0;
}
