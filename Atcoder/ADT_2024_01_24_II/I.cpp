#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<int>sa = suffix_array(str), lcp = lcp_array(str, sa);
	vector<ll>ans(n);
	for (ll i = 0; i < n; ++i)
	{
		ans[i] = n - i;
	}
	ll sum = 0;
	vector<pll>s;
	for (ll i = 0; i < n - 1; ++i)
	{
		ll cnt = 1;
		while (!s.empty() && s.back().first >= lcp[i])
		{
			auto [a, b] = s.back();
			sum -= a * b;
			cnt += b;
			s.pop_back();
		}
		sum += cnt * lcp[i];
		ans[sa[i + 1]] += sum;
		s.push_back(make_pair(lcp[i], cnt));
	}
	sum = 0;
	s.clear();
	for (ll i = n - 2; i >= 0; --i)
	{
		ll cnt = 1;
		while (!s.empty() && s.back().first >= lcp[i])
		{
			auto [a, b] = s.back();
			sum -= a * b;
			cnt += b;
			s.pop_back();
		}
		sum += cnt * lcp[i];
		ans[sa[i]] += sum;
		s.push_back(make_pair(lcp[i], cnt));
	}
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
