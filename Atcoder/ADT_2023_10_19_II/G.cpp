#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<queue<int>>q(m + 1);
	vector<vector<int>>idx(n + 1);
	vector<int>cnt(n + 1);
	set<int>active;
	for (int i = 1; i <= m; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			q[i].push(b);
		}
		int top = q[i].front();
		if (++cnt[top] == 2)
		{
			active.insert(top);
		}
		idx[top].push_back(i);
	}
	int nokori = n;
	while (!active.empty())
	{
		int pivot = *active.begin();
		for (int i = 0; i < 2; ++i)
		{
			int now = idx[pivot].back();
			idx[pivot].pop_back();
			if (--cnt[pivot] == 1)
			{
				active.erase(pivot);
			}
			q[now].pop();
			if (!q[now].empty())
			{
				int nxt = q[now].front();
				if (++cnt[nxt] == 2)
				{
					active.insert(nxt);
				}
				idx[nxt].push_back(now);
			}
		}
		n--;
	}
	cout << ((n) ? "No" : "Yes");
	return 0;
}
