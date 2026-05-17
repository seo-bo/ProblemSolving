#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<ll, ll> mm;
	vector<ll> save;
	ll tot = 0;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0;
		cin >> a;
		mm[a]++;
		save.push_back(a);
		tot += a;
	}
	sort(save.begin(), save.end());
	save.erase(unique(save.begin(), save.end()), save.end());
	int len = save.size();
	save.insert(save.end(), save.begin(), save.end());
	ll ans = 0;
	for (int i = 0; i < 2 * len;)
	{
		ll pre = (save[i] - 1 + m) % m, temp = 0, cnt = 0;
		while (i < 2 * len && cnt < len && (pre + 1) % m == save[i])
		{
			temp += save[i] * mm[save[i]];
			pre = save[i];
			i++, cnt++;
		}
		ans = max(ans, temp);
	}
	cout << tot - ans;
	return 0;
}
