#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>pos(n + 1);
	iota(pos.begin(), pos.end(), 0);
	vector<int>pre(n + 1, -1), nxt(n + 1, -1);
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (nxt[a] != -1)
		{
			pre[nxt[a]] = -1;
		}
		pre[b] = a, nxt[a] = b;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (nxt[i] != -1)
		{
			cout << 0 << ' ';
			continue;
		}
		int cnt = 0, x = i;
		while (x != -1)
		{
			x = pre[x];
			cnt++;
		}
		cout << cnt << ' ';
	}
	return 0;
}
