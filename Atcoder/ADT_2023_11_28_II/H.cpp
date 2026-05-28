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
	vector<int> nxt(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> nxt[i];
	}
	vector<int> cycle(n + 1, -1);
	vector<bool> visited(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (cycle[i] != -1)
		{
			continue;
		}
		int x = i, pivot = -1, flag = 0;
		vector<int> temp;
		while (1)
		{
			temp.push_back(x);
			visited[x] = true;
			int a = nxt[x];
			if (visited[a])
			{
				if (cycle[a] == -1)
				{
					pivot = a, flag = 1;
				}
				break;
			}
			x = a;
		}
		while (!temp.empty())
		{
			int a = temp.back();
			cycle[a] = flag;
			temp.pop_back();
			if (a == pivot)
			{
				break;
			}
		}
		while (!temp.empty())
		{
			int a = temp.back();
			cycle[a] = 0;
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
