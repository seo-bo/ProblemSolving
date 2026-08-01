#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	k = n - k;
	set<int>s;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
		if (s.find(i) != s.end())
		{
			k--;
			continue;
		}
		s.insert(i);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < k; ++i)
	{
		v.pop_back();
	}
	int now = 0;
	for (auto& i : v)
	{
		if (i != now)
		{
			break;
		}
		now++;
	}
	cout << now;
	return 0;
}
