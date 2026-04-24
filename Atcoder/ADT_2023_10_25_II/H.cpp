#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int n = 0;
		cin >> n;
		vector<pii>v(n);
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		sort(v.begin(), v.end());
		priority_queue<int, vector<int>, greater<int>>pq;
		int time = 1, idx = 0, flag = 1;
		while (idx < n || !pq.empty())
		{
			if (pq.empty() && idx < n)
			{
				time = max(time, v[idx].first);
			}
			while (idx < n && v[idx].first <= time)
			{
				pq.push(v[idx++].second);
			}
			if (!pq.empty())
			{
				if (pq.top() < time)
				{
					flag = 0;
					break;
				}
				time++;
				pq.pop();
			}
		}
		cout << ((flag) ? "Yes" : "No") << '\n';
	}
	return 0;
}
