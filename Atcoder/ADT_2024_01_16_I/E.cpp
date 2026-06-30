#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

bool visited[101][10001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<vector<int>>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int a = 0;
			cin >> a;
			v[i].push_back(a);
		}
	}
	queue<pii>q;
	visited[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		auto [cnt, pos] = q.front();
		q.pop();
		if (cnt == n)
		{
			if (pos == x)
			{
				cout << "Yes";
				return 0;
			}
			continue;
		}
		for (auto& i : v[cnt + 1])
		{
			int nxt = i + pos;
			if (nxt <= x && !visited[cnt + 1][nxt])
			{
				visited[cnt + 1][nxt] = true;
				q.push(make_pair(cnt + 1, nxt));
			}
		}
	}
	cout << "No";
	return 0;
}
