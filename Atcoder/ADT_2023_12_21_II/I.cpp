#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> A(n + 1), B(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
		pos[B[i]] = i;
	}
	dsu p(n + 1);
	vector<bool> visited(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (visited[A[i]])
		{
			continue;
		}
		int x = i;
		do
		{
			int pivot = A[x];
			visited[pivot] = true;
			int nxt = pos[pivot];
			p.merge(x, nxt);
			x = nxt;
		} while (x != i);
	}
	set<int> s;
	vector<ll> dp(n + 5);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(p.leader(i));
		dp[i] = (dp[i - 1] + dp[max(0, i - 2)]) % MOD;
	}
	ll ans = 1;
	for (auto &i : s)
	{
		int siz = p.size(i);
		if (siz == 1)
		{
			continue;
		}
		if (siz == 2)
		{
			ans = (ans * 3) % MOD;
			continue;
		}
		ll pivot = (dp[siz - 1] + dp[siz - 3]) % MOD;
		ans = (ans * pivot) % MOD;
	}
	cout << ans;
	return 0;
}
