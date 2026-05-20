#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<vector<bool>> visited(n + 1, vector<bool>(x + 1));
	vector<pii> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b] = v[i];
		cin >> a >> b;
	}
	queue<pii> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty())
	{
		auto [idx, pos] = q.front();
		q.pop();
		if (idx == n)
		{
			continue;
		}
		int nxt = idx + 1;
		auto [a, b] = v[idx + 1];
		for (auto &i : {a, b})
		{
			if (pos + i <= x && !visited[nxt][pos + i])
			{
				visited[nxt][pos + i] = true;
				q.push(make_pair(nxt, pos + i));
			}
		}
	}
	cout << ((visited[n][x]) ? "Yes" : "No");
	return 0;
}
