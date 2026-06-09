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
	vector<map<int, int>> v(10);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 10; ++j)
		{
			v[str[j] - '0'][j]++;
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < 10; ++i)
	{
		auto it = v[i].lower_bound(0);
		int temp = it->first, pre = it->first;
		if (--it->second == 0)
		{
			v[i].erase(it);
		}
		while(!v[i].empty())
		{
			auto it = v[i].upper_bound(pre);
			if(it != v[i].end())
			{
				temp += it->first - pre, pre = it->first;
				if(--it->second == 0)
				{
					v[i].erase(it);
				}
			}
			else
			{
				temp += 10 - pre;
				it = v[i].lower_bound(0);
				temp += it->first, pre = it->first;
				if(--it->second == 0)
				{
					v[i].erase(it);
				}
			}
		}
		ans = min(ans, temp);
	}
	cout << ans;
	return 0;
}
