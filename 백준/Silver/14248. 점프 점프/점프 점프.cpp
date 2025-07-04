#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<bool>visited(n + 1, 0);
	int st = 0;
	cin >> st;
	queue<int>q;
	q.push(st);
	visited[st] = true;
	vector<int>dir = { -1,1 };
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i)
		{
			int nx = cur + v[cur] * dir[i];
			if (nx >= 1 && nx <= n && !visited[nx])
			{
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}