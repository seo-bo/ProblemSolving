#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll l = 0, k = 0, c = 0;
	cin >> l >> k >> c;
	set<ll>_;
	ll left = 1, right = INT_MAX, ans = 0, idx = 0;
	for (int i = 0; i < k; ++i)
	{
		ll temp = 0;
		cin >> temp;
		_.insert(temp);
	}
	vector<ll>v(_.begin(), _.end()), diff;
	reverse(v.begin(), v.end());
	diff.push_back(l - v[0]);
	int len = v.size();
	for (int i = 0; i < len - 1; ++i)
	{
		left = max(left, v[i] - v[i + 1]);
		diff.push_back(v[i] - v[i + 1]);
	}
	diff.push_back(v.back());
	left = max({ left, l - v[0],v.back() });
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = 0, p = -1, now = diff[0];
		for (int i = 1; i < (int)diff.size(); ++i)
		{
			if (now + diff[i] > mid)
			{
				cnt++;
				p = v[i - 1];
				now = 0;
			}
			now += diff[i];
		}
		if (p == -1)
		{
			p = v.front();
			cnt++;
		}
		if (cnt <= c)
		{
			right = mid - 1;
			ans = mid;
			if (cnt < c)
			{
				idx = v.back();
			}
			else
			{
				idx = p;
			}
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << ' ' << idx;
	return 0;
}