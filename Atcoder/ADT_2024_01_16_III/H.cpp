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
	vector<int> v(n + 1), cycle(n + 1, -1), visited(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		int x = i;
		set<int> s;
		vector<int> temp;
		while (!visited[x])
		{
			s.insert(x);
			temp.push_back(x);
			visited[x] = 1;
			x = v[x];
		}
		if (s.find(x) == s.end())
		{
			for (auto &i : temp)
			{
				cycle[i] = 0;
			}
			continue;
		}
		while (!temp.empty())
		{
			cycle[temp.back()] = 1;
			if (temp.back() == x)
			{
				temp.pop_back();
				break;
			}
			temp.pop_back();
		}
		while (!temp.empty())
		{
			cycle[temp.back()] = 0;
			temp.pop_back();
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += cycle[i];
	}
	cout << ans;
	return 0;
}
