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
	vector<ll> v(n + 1), ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> ans[i];
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int nxt = (cur + 1) % (n + 1);
		nxt += (nxt == 0);
		if (ans[nxt] > ans[cur] + v[cur])
		{
			ans[nxt] = ans[cur] + v[cur];
			q.push(nxt);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
