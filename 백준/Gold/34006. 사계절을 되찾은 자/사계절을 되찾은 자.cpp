#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, A = 0, B = 0, C = 0;
	cin >> n >> A >> B >> C;
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	vector<vector<tp>>parent(2 * n + 5, vector<tp>(2 * n + 5, make_tuple(-1, -1, -1)));
	vector<vector<int>>visited(2 * n + 5, vector<int>(2 * n + 5, INT_MAX));
	queue<pii>q;
	q.push(make_pair(A, B));
	visited[A][B] = 0;
	while (!q.empty())
	{
		auto [aa, bb] = q.front();
		q.pop();
		int cc = 3 * n - (aa + bb);
		if (aa + a < 2 * n && cc - a > 0)
		{
			int na = aa + a, nb = bb;
			if (visited[na][nb] > visited[aa][bb] + 1)
			{
				visited[na][nb] = visited[aa][bb] + 1;
				q.push(make_pair(na, nb));
				parent[na][nb] = make_tuple(aa, bb, 0);
			}
		}
		if (bb + b < 2 * n && aa - b > 0)
		{
			int na = aa - b, nb = bb + b;
			if (visited[na][nb] > visited[aa][bb] + 1)
			{
				visited[na][nb] = visited[aa][bb] + 1;
				q.push(make_pair(na, nb));
				parent[na][nb] = make_tuple(aa, bb, 1);
			}
		}
		if (cc + c < 2 * n && bb - c > 0)
		{
			int na = aa, nb = bb - c;
			if (visited[na][nb] > visited[aa][bb] + 1)
			{
				visited[na][nb] = visited[aa][bb] + 1;
				q.push(make_pair(na, nb));
				parent[na][nb] = make_tuple(aa, bb, 2);
			}
		}
	}
	if (visited[n][n] == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << visited[n][n] << '\n';
	string ans;
	int x = n, y = n;
	while (1)
	{
		auto [aa, bb, cc] = parent[x][y];
		if (aa == -1)
		{
			break;
		}
		ans += char('A' + cc);
		x = aa, y = bb;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}