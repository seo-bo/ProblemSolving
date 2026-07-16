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
	vector<int>A(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[A[i]];
	}
	vector<ll>dp(n + 100);
	dp[1] = 1;
	for (int i = 2; i <= n + 5; ++i)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}
	ll ans = 1;
	vector<int>visited(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		int len = 0, x = i;
		while (!visited[x])
		{
			visited[x] = 1;
			len++;
			x = v[x];
		}
		ll temp = (dp[len - 1] + dp[len + 1]) % MOD;
		/*
		피보나치 자체가 2칸 밀려있으니 원래는 len + 2
		C#1 - 사이클에서 첫번째를 0으로 잡음 : 두번째와 마지막이 1로 고정되서 len - 1에 대한 피보나치
		C#2 - 사이클에서 첫번째를 1로 잡음 : 정해진건 하나 이므로 len + 1에 대한 피보나치
		*/
		ans = (ans * temp) % MOD;
	}
	cout << ans;
	return 0;
}
