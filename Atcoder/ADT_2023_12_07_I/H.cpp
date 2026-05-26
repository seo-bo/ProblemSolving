#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int> A(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> A[i];
	}
	vector<vector<int>> graph(n + 1);
	map<pii, int> mm;
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		if (a > b)
		{
			swap(a, b);
		}
		mm[make_pair(a, b)] = 0;
	}
	vector<vector<int>> parent(n + 1, vector<int>(n + 1, -1));
	auto cal = [&](int start)
	{
		queue<int> q;
		parent[start][start] = start;
		q.push(start);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto &i : graph[cur])
			{
				if (parent[start][i] == -1)
				{
					parent[start][i] = cur;
					q.push(i);
				}
			}
		}
	};
	for (int i = 1; i <= n; ++i)
	{
		cal(i);
	}
	int sum = 0;
	for (int i = 1; i <= m - 1; ++i)
	{
		int now = A[i], end = A[i + 1];
		while (end != now)
		{
			int nxt = parent[end][now];
			int a = now, b = nxt;
			if (a > b)
			{
				swap(a, b);
			}
			mm[make_pair(a, b)]++;
			sum++;
			now = nxt;
		}
	}
	int pivot = (sum + k);
	if (pivot % 2 || pivot < 0)
	{
		cout << 0;
		return 0;
	}
	pivot /= 2;
	vector<ll> dp(pivot + 1);
	dp[0] = 1;
	for (auto &[a, b] : mm)
	{
		for (int j = pivot; j >= b; --j)
		{
			dp[j] = (dp[j] + dp[j - b]) % MOD;
		}
	}
	cout << dp[pivot];
	return 0;
}
