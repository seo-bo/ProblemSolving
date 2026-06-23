#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>in, out, x;
	for (ll i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		in.push_back(a), out.push_back(a + b);
		x.push_back(a), x.push_back(a + b);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	vector<ll>ans(n + 1);
	ll cnt = 0, idx = 0, jdx = 0, alen = in.size(), blen = out.size(), pre = 0;
	for (auto& i : x)
	{
		ans[cnt] += i - pre;
		while (idx < alen && in[idx] == i)
		{
			cnt++, idx++;
		}
		while (jdx < blen && out[jdx] == i)
		{
			cnt--, jdx++;
		}
		pre = i;
	}
	for (ll i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
