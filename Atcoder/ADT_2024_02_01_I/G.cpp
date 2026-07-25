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
	string str;
	cin >> str;
	vector<ll>cnt(10);
	for (auto& i : str)
	{
		cnt[i - '0']++;
	}
	ll ans = 0, lim = 1;
	for (int i = 0; i < n; ++i)
	{
		lim *= 10;
	}
	for (ll i = 0; i * i <= lim; ++i)
	{
		string temp = to_string(i * i);
		vector<ll>t(10);
		for (auto& k : temp)
		{
			t[k - '0']++;
		}
		t[0] += n - temp.size();
		ans += (cnt == t);
	}
	cout << ans;
	return 0;
}
